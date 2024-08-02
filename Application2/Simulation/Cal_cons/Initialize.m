clear all
%% circuit specifications
Ts=0.01; % simulation step
tmax=400/Ts;  % run time
Ns=3;  % number of subsystems

M=1*[3.5 4 3.75];
D=1.1*[2 2.75 2.4];
Tg=0.5*[40 25 32];
Tch=1*[50 10 30];
Rw=1.5*[1 1 1];
s=[0 0 0];
T=zeros(3,3);

T(1,2)=7.54;
T(1,3)=T(1,2);
T(2,1)=7.54;
T(2,3)=T(2,1);
T(3,1)=7.54;
T(3,2)=T(3,1);

w=zeros(2,3,tmax);
delta_PL=10*[0.2 0.2 0.2];
delta_Pe=0*ones(1,3);
% Td=[5;10;15;20;200];
% % Td=[0.1;5;10;15;200];
% w(:,1,Td(1)/Ts)=[2;0];
% w(:,2,Td(2)/Ts)=[2;0];
% w(:,3,Td(3)/Ts)=[2;0];
% w(:,3,Td(4)/Ts)=[1;0];
% w(:,1,Td(5)/Ts)=[-2;0];
% w(:,2,Td(5)/Ts)=[-2;0];
% w(:,3,Td(5)/Ts)=[-3;0];
Td=[10;150;250];
w(:,1,Td(1)/Ts)=[2;0];
w(:,1,Td(2)/Ts)=[2;0];
w(:,2,Td(2)/Ts)=[2;0];
w(:,1,Td(3)/Ts)=[2;0];
w(:,2,Td(3)/Ts)=[2;0];
w(:,3,Td(3)/Ts)=[2;0];

beta=0.1*[1 1 1];
bar_T=zeros(1,3);
for i=1:3
    for j=1:3
        bar_T(1,i)=bar_T(1,i)+T(i,j);
    end
end

%% topology
% physical coupling topology
A_com_p =  [0 1 1; 1 0 1; 1 1 0];
% cyber communication topology
A_comm=[0 1 1; 1 0 1; 1 1 0];
D_comm = zeros(Ns,Ns);
for i=1:Ns
    for j=1:Ns
        if A_comm(i,j)~=0
            D_comm(i,i)=D_comm(i,i)+A_comm(i,j);
        end
    end
end
L_comm = D_comm - A_comm;
L_eig = eigs(-L_comm);



%% continues model
A_s=cell(3,3);
B_s=cell(3,3);
AD=cell(3,3);
K=cell(3,3);
A=cell(3,3);
B=cell(3,3);
C=cell(3,3);

for i=1:3
    A_s{i,i}=[-D(i)/M(i) 1/M(i) 0 -1/M(i); 0 -1/Tch(i) 1/Tch(i) 0; -1/(Tg(i)*Rw(i)) 0 -1/Tg(i) 0; bar_T(i) 0 0 0];
    B_s{i,i}=[0; 0; 1/Tg(i); 0];
    AD{i,i}=[-1/M(i) 0; 0 0; 0 s(i)/Tg(i); 0 0];
    for j=1:3
        if j~=i
            A_s{i,j}=-T(i,j)*[0 0 0 0; 0 0 0 0; 0 0 0 0; 1 0 0 0];
            B_s{i,j}=zeros(4,1);
            AD{i,j}=zeros(4,2);
        end
    end
end

for i=1:3
    K{i,i}=-1*1*[beta(i),0,0,1];
    C{i,i}=[beta(i),0,0,1];
    for j=1:3
        if j~=i
            K{i,j}=zeros(1,4);
            C{i,j}=zeros(1,4);
        end
    end
end

As_all=cell2mat(A_s);
Bs_all=cell2mat(B_s);
K_all=cell2mat(K);
AD_all=cell2mat(AD);
C_all=cell2mat(C);

%% discrete model
[A_all,B_all]=c2d(As_all,Bs_all,Ts);
for i=1:3
    A{i,i}=eye(4)+Ts*A_s{i,i};
    B{i,i}=Ts*B_s{i,i};
    for j=1:3
        if j~=i
            A{i,j}=Ts*A_s{i,j};
            B{i,j}=zeros(4,1);
        end
    end
end


%% settings of the optimization
ub=cell(1,Ns); xb=cell(1,Ns); xFb=cell(1,Ns);
Q=cell(1,Ns); % matrices in the cost function
P=cell(1,Ns); R=cell(1,Ns);

for i=1:Ns
    % ub{1,i}=1e-2*[-1,1];
    % xb{1,i}=diag([0.01,0.005,0.0005,0.0001,5,0.5])*kron(ones(6,1),[-1,1]);
    % xFb{1,i}=diag([0.01,0.005,0.0005,0.0001,5,0.5])*kron(ones(6,1),[-1,1]);
    
    Q{1,i}=diag([1,1,1,1]);
    P{1,i}=1.5*diag([1,1,1,1]);
    R{1,i}=1;
    % [P,L,K] = dare(A,B,Q,R);
end

N=4;  % time window for optimization
N_delay_trans=30;
N_delay_process=100;
N_delay_comm=N_delay_trans+N_delay_process; % delay
% N_delay_comm=0;

Ay=1*[beta(i),0,0,1]'; % magnitude of the attack on the state
Au=1; % magnitude of the attack on the control signal
Omega=0.1; % angular frequency
Steps_con=500; % control period
Steps_fig=1000; % draw period
Steps_dis=100; % disp period

node_eng=[0.75,0.7,0.65,0.62,0.57,0.55,0.5];
att_eng=[0.27,0.22,0.17,0.12,0.1,0.07,0.06];
ps_u=cell(1,Ns);
pa_u=cell(1,Ns);
ps_x=cell(Ns,Ns);
pa_x=cell(Ns,Ns);
for i=1:Ns
    ps_u{1,i}=node_eng;
    pa_u{1,i}=att_eng;
    ps_x{i,i}=node_eng;
    pa_x{i,i}=att_eng;
    for j=1:Ns
        if A_comm(i,j)>0
            ps_x{i,j}=node_eng;
            pa_x{i,j}=att_eng;
        end
    end
end

system_strategy_all=0*ones(29,5);
system_strategy_all(29,:)=1;
attacker_strategy_all=0*ones(29,5);
attacker_strategy_stoc=1/29*ones(29,5);
state_rank=[0.015,0.05,0.2,0.4];
warning('off');

%% used for testing of the closed-loop system
%%
% tmax=400/Ts;
% x_all=zeros(12,tmax+1);
% ACE_all=zeros(3,tmax+1);
% x_all(1:4,1)=x0{1,1};x_all(5:8,1)=x0{1,2};x_all(9:12,1)=x0{1,3};
% for k=1:tmax 
%     x_all(:,k+1)=(A_all+B_all*K_all)*x_all(:,k)+AD_all*[w(:,1,k);w(:,2,k);w(:,3,k)];
%     ACE_all(:,k)=C_all*x_all(:,k);
% end
% tt=1:tmax;
% figure
% subplot(3,1,1),plot(tt,x_all(1,tt),tt,x_all(2,tt),tt,x_all(3,tt),tt,x_all(4,tt))
% legend('A1-1','A1-2','A1-3','A1-4')
% subplot(3,1,2),plot(tt,x_all(5,tt),tt,x_all(6,tt),tt,x_all(7,tt),tt,x_all(8,tt))
% legend('A2-1','A2-1','A2-1','A2-1')
% subplot(3,1,3),plot(tt,x_all(9,tt),tt,x_all(10,tt),tt,x_all(11,tt),tt,x_all(12,tt))
% legend('A3-1','A3-1','A3-1','A3-1')
% 
% figure
% plot(tt,x_all(1,tt),tt,x_all(5,tt),tt,x_all(9,tt))
% legend('df1','df2','df3')
% figure
% plot(tt,x_all(4,tt),tt,x_all(8,tt),tt,x_all(12,tt))
% legend('dP1','dP2','dP3')
% 
% figure
% plot(ACE_all');
% legend('ACE1','ACE2','ACE3')

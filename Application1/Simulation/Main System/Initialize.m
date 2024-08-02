clear all
%% circuit specifications
Ts=1e-4; % simulation step
Ns=5;  % number of subsystems
U_in = [100 80 80 100 120]; % voltage source

% RLC filters
R_t = 0*[0.5 0.2 0.2 0.5 0.5];
L_t = 2e-3*ones(1,Ns);
C_t = 2000*1e-6*ones(1,Ns);

% tie lines
R_ij=zeros(Ns,Ns);
R_ij(1,2) = 0.5;
R_ij(2,3) = 1;
R_ij(3,4) = 0.2;
R_ij(4,5) = 0.6;
R_ij(5,1) = 0.8;
R_ij(2,4) = 0.5; 
R_ij(2,5) = 0.3; 
R_ij(1,4) = 0.1; 

R_ij(4,2) = R_ij(2,4); 
R_ij(5,2) = R_ij(2,5); 
R_ij(4,1) = R_ij(1,4); 
R_ij(2,1) = R_ij(1,2);
R_ij(3,2) = R_ij(2,3);
R_ij(4,3) = R_ij(3,4);
R_ij(5,4) = R_ij(4,5);
R_ij(1,5) = R_ij(5,1);

% loads
R_L = 1*[10 10 13 10 10];

%% topology
% physical coupling topology
A_com_p =  [0 1 0 1 1;
    1 0 1 1 1;
    0 1 0 1 0;
    1 1 1 0 1;
    1 1 0 1 0];
% cyber communication topology
A_comm = [0 1 0 0 1;
    1 0 1 0 0;
    0 1 0 1 0;
    0 0 1 0 1;
    1 0 0 1 0];
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


%% inner control loops
kp_inner_I = 0.07*ones(1,Ns); % Out, voltage
ki_inner_I = 1*ones(1,Ns);
kp_inner_II = 0.01*ones(1,Ns); % In, current
ki_inner_II = 1*ones(1,Ns);

%% control objectives
I_max = [1 1 1.8 1.8 1.8];
theta = I_max;
Rd = [1.9 1.9 0.9 1 1.02];
V_ref=48; % voltage rate
K_bar=0.1;  % gain of the observer

%% discrete model with xj-xi as coupling
A = cell(Ns,Ns);
B = cell(Ns,Ns);

for i=1:Ns
    A{i,i}=zeros(6,6);
    B{i,i}=zeros(6,1);
    % Aii Bii Cii
    A{i,i}(1,1) = 1-Ts/C_t(i)/R_L(i);
    A{i,i}(1,2) = Ts*I_max(i)/C_t(i);
    A{i,i}(2,1) = -Ts/I_max(i)/L_t(i)*(1+U_in(i)*kp_inner_II(i)*kp_inner_I(i));
    A{i,i}(2,2) = 1-Ts*R_t(i)/L_t(i)-Ts*U_in(i)/L_t(i)*(kp_inner_II(i)+kp_inner_II(i)*kp_inner_I(i)*Rd(i));
    A{i,i}(2,3) = Ts*U_in(i)/I_max(i)/L_t(i)*kp_inner_II(i)*ki_inner_I(i);
    A{i,i}(2,4) = Ts*U_in(i)/I_max(i)/L_t(i)*ki_inner_II(i);
    A{i,i}(3,1) = -Ts;
    A{i,i}(3,2) = -Ts*I_max(i)*Rd(i);
    A{i,i}(3,3) = 1;
    A{i,i}(4,1) = -Ts*kp_inner_I(i);
    A{i,i}(4,2) = -I_max(i)*(Ts+Ts*kp_inner_I(i)*Rd(i));
    A{i,i}(4,3) = Ts*ki_inner_I(i);
    A{i,i}(4,4) = 1;
    A{i,i}(5,1) = -1+Ts/C_t(i)/R_L(i);
    A{i,i}(5,2) = -Ts*I_max(i)/C_t(i);
    A{i,i}(5,5) = 1;
    A{i,i}(6,6) = 1;
    B{i,i}(2) = Ts*U_in(i)/I_max(i)/L_t(i)*kp_inner_II(i)*kp_inner_I(i);
    B{i,i}(3) = Ts;
    B{i,i}(4) = Ts*kp_inner_I(i);
    % rank(ctrb(A{i,i},B{i,i}))
    for j=1:Ns
        if j~=i
            A{i,j} = zeros(6,6);
            B{i,j} = zeros(6,1);
            if R_ij(i,j)~=0 % Aij Bij Cij
                A{i,j}(1,1) = Ts/( C_t(i)*R_ij(i,j) );
                A{i,j}(5,1) = -Ts/( C_t(i)*R_ij(i,j) );
            end
            if A_comm(i,j)~=0
                A{i,j}(5,5) = Ts*K_bar;
                A{i,j}(6,2) = 1;
            end
        end
    end
    % rank(ctrb(A{i,i},B{i,i}))
end

%% global system
A_all=cell2mat(A);
B_all=cell2mat(B);

%% discrete model used in node
Ac = cell(Ns,Ns);
Bc = cell(Ns,Ns);
for i=1:Ns
    Bc{i,i} = B{i,i};
    temp=zeros(6,6);
    for j=1:Ns
        if j~=i
            if A_comm(i,j)>0
                Ac{i,j}=A{i,j};
                Bc{i,j}=B{i,j};
                temp = temp+A{i,j};
            else
                Ac{i,j}=zeros(6,6);
                Bc{i,j}=zeros(6,1);
            end
        end
    end
    Ac{i,i} = A{i,i}-temp;
end

%% discrete model with xj as coupling
Aa = cell(Ns,Ns);
Ba = cell(Ns,Ns);
K=cell(Ns,Ns); % gain matrix for feedback
% can be written as Aaiixi+Baui+sum(Aaij(xj-xi))
% Aij=Aaij,Aii=Aaii-sum(Aaij),B=Ba

for i=1:Ns
    Ba{i,i} = B{i,i};
    temp=zeros(6,6);
    for j=1:Ns
        if j~=i
            Aa{i,j}=A{i,j};
            Ba{i,j}=B{i,j};
            if R_ij(i,j)~=0
                temp = temp+Aa{i,j};
            end
            K{i,j}=zeros(1,6);
        end
    end
    Aa{i,i} = A{i,i}-temp;
    K{i,i}=[0,0,0,0,0.0002,0.02];
    abs(eig(Aa{i,i}+Ba{i,i}*K{i,i}));
end
Aa_all=cell2mat(Aa);
Ba_all=cell2mat(Ba);
K_all=cell2mat(K);

A_all=Aa_all;
B_all=Ba_all;
A=Aa;
B=Ba;

% A_all=cell2mat(A);
% B_all=cell2mat(B);
% K_all=cell2mat(K);
% abs(eig(A_all+B_all*K_all))'

%% settings of the optimization
ub=cell(1,Ns); xb=cell(1,Ns); xFb=cell(1,Ns);
Q=cell(1,Ns); % matrices in the cost function
P=cell(1,Ns); R=cell(1,Ns);

for i=1:Ns
    ub{1,i}=1e-2*[-1,1];
    xb{1,i}=diag([0.01,0.005,0.0005,0.0001,5,0.5])*kron(ones(6,1),[-1,1]);
    xFb{1,i}=diag([0.01,0.005,0.0005,0.0001,5,0.5])*kron(ones(6,1),[-1,1]);
    
    Q{1,i}=diag([1,1,1,1,1,1]);
    P{1,i}=1.5*diag([1,1,1,1,1,1]);
    R{1,i}=1;
    % [P,L,K] = dare(A,B,Q,R);
end

N=150;  % time window for optimization
N_delay_trans=30;
N_delay_process=100;
N_delay_comm=N_delay_trans+N_delay_process; % delay

Ay=[0,0,0,0,1,0.1]'; % magnitude of the attack on the state
Au=0.1; % magnitude of the attack on the control signal
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
% tmax=2/Ts;
% x_all=zeros(30,tmax);
% x_all(5,1)=48;x_all(11,1)=48;x_all(17,1)=48;x_all(23,1)=48;x_all(29,1)=48;
% for k=1:tmax 
%     x_all(:,k)=(A_all+B_all*K_all)^(k-1)*x_all(:,1);
% end
% figure
% subplot(5,1,1),plot(1:tmax,x_all(1,:),1:tmax,x_all(2,:),1:tmax,x_all(3,:),1:tmax,x_all(4,:),1:tmax,x_all(5,:),1:tmax,x_all(6,:))
% legend('DG1-dV','DG1-dI','DG1-pieV','DG1-pieI','DG1-eV','DG1-eI')
% subplot(5,1,2),plot(1:tmax,x_all(7,:),1:tmax,x_all(8,:),1:tmax,x_all(9,:),1:tmax,x_all(10,:),1:tmax,x_all(11,:),1:tmax,x_all(12,:))
% legend('DG2-dV','DG2-dI','DG2-pieV','DG2-pieI','DG2-eV','DG2-eI')
% subplot(5,1,3),plot(1:tmax,x_all(13,:),1:tmax,x_all(14,:),1:tmax,x_all(15,:),1:tmax,x_all(16,:),1:tmax,x_all(17,:),1:tmax,x_all(18,:))
% legend('DG3-dV','DG3-dI','DG3-pieV','DG3-pieI','DG3-eV','DG3-eI')
% subplot(5,1,4),plot(1:tmax,x_all(19,:),1:tmax,x_all(20,:),1:tmax,x_all(21,:),1:tmax,x_all(22,:),1:tmax,x_all(23,:),1:tmax,x_all(24,:))
% legend('DG4-dV','DG4-dI','DG4-pieV','DG4-pieI','DG4-eV','DG4-eI')
% subplot(5,1,5),plot(1:tmax,x_all(25,:),1:tmax,x_all(26,:),1:tmax,x_all(27,:),1:tmax,x_all(28,:),1:tmax,x_all(29,:),1:tmax,x_all(30,:))
% legend('DG5-dV','DG5-dI','DG5-pieV','DG5-pieI','DG5-eV','DG5-eI')
% 
% V_all=zeros(5,tmax);
% I_all=zeros(5,tmax);
% for k=1:tmax
%     V_all(1,k)=sum(x_all(1,1:k));
%     V_all(2,k)=sum(x_all(7,1:k));
%     V_all(3,k)=sum(x_all(13,1:k));
%     V_all(4,k)=sum(x_all(19,1:k));
%     V_all(5,k)=sum(x_all(25,1:k));
%     I_all(1,k)=I_max(1)*sum(x_all(2,1:k));
%     I_all(2,k)=I_max(2)*sum(x_all(8,1:k));
%     I_all(3,k)=I_max(3)*sum(x_all(14,1:k));
%     I_all(4,k)=I_max(4)*sum(x_all(20,1:k));
%     I_all(5,k)=I_max(5)*sum(x_all(26,1:k));
% end
% figure
% subplot(2,1,1),plot(V_all')
% legend('DG1-V','DG2-V','DG3-V','DG4-V','DG5-V')
% subplot(2,1,2),plot(I_all')
% legend('DG1-I','DG2-I','DG3-I','DG4-I','DG5-I')

%% used for testing of the droop control system
% tmax=2/Ts;
% x_all=zeros(20,tmax);
% n_droop=[1:4,7:10,13:16,19:22,25:28];
% x_all(:,1)=B_all(n_droop)*48;
% for k=1:tmax 
%     x_all(:,k)=A_all(n_droop,n_droop)^(k-1)*x_all(:,1);
% end
% 
% V_all=zeros(5,tmax);
% I_all=zeros(5,tmax);
% for k=1:tmax
%     V_all(1,k)=sum(x_all(1,1:k));
%     V_all(2,k)=sum(x_all(5,1:k));
%     V_all(3,k)=sum(x_all(9,1:k));
%     V_all(4,k)=sum(x_all(13,1:k));
%     V_all(5,k)=sum(x_all(17,1:k));
%     I_all(1,k)=I_max(1)*sum(x_all(2,1:k));
%     I_all(2,k)=I_max(2)*sum(x_all(6,1:k));
%     I_all(3,k)=I_max(3)*sum(x_all(10,1:k));
%     I_all(4,k)=I_max(4)*sum(x_all(14,1:k));
%     I_all(5,k)=I_max(5)*sum(x_all(18,1:k));
% end
% figure
% subplot(2,1,1),plot(V_all')
% legend('DG1-V','DG2-V','DG3-V','DG4-V','DG5-V')
% subplot(2,1,2),plot(I_all')
% legend('DG1-I','DG2-I','DG3-I','DG4-I','DG5-I')



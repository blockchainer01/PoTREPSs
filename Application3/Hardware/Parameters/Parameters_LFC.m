%%
Ts=1e-3;
%%
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

%% settings of PoT
N_area=3;
N_BC_node=7;
N_BC_group = N_area;
N_blockchain=N_BC_node*ones(1,N_area);
node_eng=[0.75,0.7,0.65,0.62,0.57,0.55,0.5];
att_eng=[0.27,0.22,0.17,0.12,0.1,0.07,0.06];
alpha_single=zeros(1,7);  % 7 nodes/channel
beta_single=zeros(1,7);   % 7 nodes/channel
for i=1:N_BC_node
    alpha_single(i)=pa(i)/ps(i);
    beta_single(i)=pa(i)/ps(i); 
end

Communication_time = 50*Ts;
Waiting_time = 100*Ts;

%%
bar_p_ref=0.3;
bar_p_mech=0.0017;

%%
x=[x1';x2';x3'];
dx=zeros(3,4);
u=[u1;u2;u3];

w=zeros(2,3);
delta_Pe=0*ones(1,3);
for i=1:3
    w(:,i)=[delta_PL(i); delta_Pe(i)];
end

%% load variations
% 改simulink
%%
bar_T=zeros(1,3);
for i=1:3
    for j=1:3
        bar_T(1,i)=bar_T(1,i)+T(i,j);
    end
end

A=cell(1,3);
A_=cell(3,3);
B=cell(1,3);
A_D=cell(1,3);

for i=1:3
    A{1,i}=[-D(i)/M(i) 1/M(i) 0 -1/M(i); 0 -1/Tch(i) 1/Tch(i) 0; -1/(Tg(i)*Rw(i)) 0 -1/Tg(i) 0; bar_T(i) 0 0 0];
    B{1,i}=[0; 0; 1/Tg(i); 0];
    A_D{1,i}=[-1/M(i) 0; 0 0; 0 s(i)/Tg(i); 0 0];
    for j=1:3
        A_{i,j}=-T(i,j)*[0 0 0 0; 0 0 0 0; 0 0 0 0; 1 0 0 0];
    end
end

%%
for i=1:3
    Inter=zeros(4,1);
    for j=1:3
        Inter=Inter+A_{i,j}*x(j,:)';
    end
    dx(i,:)=A{1,i}*x(i,:)'+Inter+B{1,i}*u(i)+A_D{1,i}*w(:,i);
end

%%
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

%%
Ay=1*[beta(i),0,0,1]'; % magnitude of the attack on the state
Au=1; % magnitude of the attack on the control signal
Omega=0.1; % angular frequency
Steps_con=100; % control period
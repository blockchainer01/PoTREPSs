%
% clear all
%% ����ϵͳ����
load('.\SystemMatrices\A_all.mat');
load('.\SystemMatrices\B_all.mat');
%% 
Ts= 0.0001; % ʵ��ϵͳ�������� 0.1 ms
% Tc=0.01; % ��������Ϊ 10 ms
% Tc=0.02; % ��������Ϊ 20 ms
Tc=0.025; % ��������Ϊ 25 ms
Ns=5;  % ��ϵͳ������
dim=4; % ģ��ά��

% %% 20 repeats/ parameters in comparision
% node_eng_u=[0.75,0.7,0.65,0.62,0.57,0.55,0.5];
% att_eng_u=0.7*[0.15,0.17,0.15,0.11,0.05,0.05,0.05];
% node_eng_x=[0.75,0.7,0.65,0.62,0.57,0.55,0.5];
% att_eng_x=0.7*[0.15,0.17,0.15,0.11,0.05,0.05,0.05];
% 20 repeats 91%
node_eng_u=[0.73,0.7,0.64,0.62,0.57,0.55,0.5];
att_eng_u=[0.18,0.18,0.17,0.14,0.05,0.05,0.05];
node_eng_x=[0.73,0.7,0.64,0.62,0.57,0.55,0.5];
att_eng_x=[0.18,0.18,0.17,0.14,0.05,0.05,0.05];
% %% 20 repeats 93%
% node_eng_u=[0.75,0.7,0.65,0.62,0.57,0.55,0.5];
% att_eng_u=[0.15,0.17,0.15,0.11,0.05,0.05,0.05];
% node_eng_x=[0.75,0.7,0.65,0.62,0.57,0.55,0.5];
% att_eng_x=[0.15,0.17,0.15,0.11,0.05,0.05,0.05];

% Application 1 with game strategy
% node_eng=[0.75,0.7,0.65,0.62,0.57,0.55,0.5];
% att_eng=[0.27,0.22,0.17,0.12,0.1,0.07,0.06];

% node_eng_u=[0.75,0.7,0.65,0.62,0.57,0.55,0.5];
% att_eng_u=[0.27,0.22,0.17,0.12,0.1,0.07,0.06];
% node_eng_x=[0.75,0.7,0.65,0.62,0.57,0.55,0.5];
% att_eng_x=[0.27,0.22,0.17,0.12,0.1,0.07,0.06];

ps_u=node_eng_u;
pa_u=att_eng_u;
ps_x=node_eng_x;
pa_x=att_eng_x;

attack_probability_x=zeros(1,7);
attack_probability_u=zeros(1,7);
for n=1:7
    % attacked and successful
    attack_probability_u(n)=pa_u(n)/ps_u(n);
end
for n=1:7
    attack_probability_x(n)=pa_x(n)/ps_x(n);
end

%%
Ax1=[1; 0.1; 0.01; 0.02];
Ax=[Ax1;Ax1;Ax1;Ax1;Ax1];
% Ax=1*ones(20,1); % magnitude of the attack on the state
% Au=0.25*ones(5,1); % magnitude of the attack on the control signal
Au=0.1*ones(5,1); % magnitude of the attack on the control signal
Omega=0.1; % angular frequency
%%
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

%%
I_max = [1 1 1.8 1.8 1.8]';
V_ref=48;


%% ȫ�ִ�ϵͳ
A = A_all;
B = B_all;


%% ϵͳ����
% d_SC ����ͨ�� d_CA ǰ��ͨ��
% ����������һ��ΪTs��
d_SC=1000; % 1000*Ts=1000*0.0001s=100ms
d_SC_sec = d_SC*Ts/Tc;
d_CA=1000;
d_CA_sec = d_CA*Ts/Tc;
% d_SC=0;
% d_CA=0;
t_droop=5/Ts;
t_max=20/Ts;
x=zeros(dim*Ns,t_max+1);
x_pred=zeros(dim*Ns,t_max+1);
u=zeros(Ns,t_max+d_CA);
u_pred=zeros(Ns,t_max+d_CA);
Vref=48;


V=zeros(Ns,t_max+1);
I=zeros(Ns,t_max+1);
V_pred=zeros(Ns,t_max+1);
I_pred=zeros(Ns,t_max+1);

%% �´�����
for t=1:t_droop
    x(:,t+1) = A*x(:,t)+B*u(:,t)+B*kron(ones(Ns,1),Vref);
    for i=1:Ns % �Ե�i��subsystem
        V(i,t+1)=x(dim*(i-1)+1,t+1);
        % V_pred(i,t+1)=V(i,t+1);
        I(i,t+1)=x(dim*(i-1)+2,t+1);
        % I_pred(i,t+1)=I(i,t+1);
    end
end

%% ����ʽ���Ʋ���
%% �μ����Ʋ���
% ���Ʋ���
G_I=0.1;
G_V=0.04*diag([1 1 1 1 1]);

Len_sec =length(1:Tc/Ts:t_max);
attack_flag_x = cell(1,Ns);
attack_flag_u = cell(1,Ns);
for i=1:Ns
    attack_flag_x{1,i} = zeros(1,t_max);
    attack_flag_u{1,i} = zeros(1,t_max);
end

xxd_ = zeros(dim*Ns,Len_sec);
xxd_true = zeros(dim,1);


tic
for t=1+t_droop:t_max
    
    % ������������Tcʱ�����ڸ���
    if mod(t,Tc/Ts)==1
        if t>=1+t_droop+d_SC
            x_dg = zeros(1,dim);
            %% communication data
            for i=1:Ns
                x_dg = i+(i-1)*(dim-1):i+(i-1)*(dim-1)+dim-1;%index
                attack_flag_x{1,i}(t) = Consensus(attack_probability_x);
                xxd_true=x(x_dg,t-d_SC);% SC��ʱ���յ���ʱ����
                %% xxd=?
                if attack_flag_x{1,i}(t)==0  % safe from attack
    %                 xxd=xxd_true;
                    xxd_(x_dg,t)=xxd_true;
                else % attacked                   
                    xxd_(x_dg,t)=xxd_true+Ax(x_dg)*sin(Omega*(t-d_SC));
                    
                end
            end
            xxd = xxd_(:,t);
            % end communication
            %% ��ʼԤ�⣬����SC��CA
            for k=1:d_SC+d_CA
                xxd=A*xxd+B*u(:,t-d_SC+k-1)+B*kron(ones(Ns,1),Vref);
            end
            x_pred(:,t+d_CA)=xxd;
            for i=1:Ns % �Ե�i��subsystem
                V_pred(i,t+d_CA)=x_pred(dim*(i-1)+1,t+d_CA);
                I_pred(i,t+d_CA)=x_pred(dim*(i-1)+2,t+d_CA);
            end
            u_pred(:,t+d_CA)=G_I*(-L_comm*(I_pred(:,t+d_CA)./I_max))...
                +G_V*(kron(ones(Ns,1),Vref-sum(V_pred(:,t+d_CA))/Ns))+u(:,t+d_CA-1);
        end
        %% communication control command
        for i=1:Ns
            attack_flag_u{1,i}(t) = Consensus(attack_probability_u);
            if attack_flag_u{1,i}(t)==0  % safe from attack
                u(i,t+d_CA)=u_pred(i,t+d_CA);
            else % attacked
                u(i,t+d_CA)=u_pred(i,t+d_CA)+Au(i)*sin(Omega*(t+d_CA));
            end
        end
        % end communication
        for l=1:Tc/Ts
            u(:,t+d_CA+l-1)=u(:,t+d_CA);
        end
    end

    % ϵͳ�ݻ� ����Tcʱ�������ݻ�
    x(:,t+1) = A*x(:,t)+B*u(:,t)+B*kron(ones(Ns,1),Vref);
    for i=1:Ns % �Ե�i��subsystem
        V(i,t+1)=x(dim*(i-1)+1,t+1);
        I(i,t+1)=x(dim*(i-1)+2,t+1);
    end
end

%% ��ͼ
t=1:t_max;
figure(1);
subplot(2,1,1),plot(t,V(1,t),t,V(2,t),t,V(3,t),t,V(4,t),t,V(5,t));
legend('V1','V2','V3','V4','V5')
subplot(2,1,2),plot(t,I(1,t),t,I(2,t),t,I(3,t),t,I(4,t),t,I(5,t));
legend('I1','I2','I3','I4','I5')

%%
run_time=toc;
% save 'RunResult.mat' x xxd_ u u_pred V I Ts Tc...
%     Ax Au Omega attack_flag_u attack_flag_x t_max Len_sec run_time



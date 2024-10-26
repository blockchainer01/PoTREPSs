% clear all

% %% load system matrices
load('A_all.mat');
load('B_all.mat');
%% 
Ts= 0.0001; % simulation step
Tc=0.025; % control step
Ns=5;  % number of subsystems
dim=4; % dimension of the system model

node_eng_u=[0.73,0.7,0.64,0.62,0.57,0.55,0.5];
att_eng_u=[0.17,0.18,0.17,0.14,0.05,0.05,0.05];
node_eng_x=[0.73,0.7,0.64,0.62,0.57,0.55,0.5];
att_eng_x=[0.17,0.18,0.17,0.14,0.05,0.05,0.05];

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
Ax=[Ax1;Ax1;Ax1;Ax1;Ax1]; % magnitude of the attack on the state Revise it
Au=0.1*ones(5,1); % magnitude of the attack on the control signal
Omega=0.1; % angular frequency

%% control objectives
I_max = [1 1 1.8 1.8 1.8]';
Vref=48;
%% Global system
A = A_all;
B = B_all;

% control parameter
G_I=0.11;
G_V=0.05*diag([1 1 1 1 1]);

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


%% Simulation time
t_droop=5/Ts;
t_max=20/Ts;

Len_sec =length(1:Tc/Ts:t_max);

Steps_fig=1000; % draw period
Steps_dis=100; % disp period

% 0/1 indicates whether the corresponding node is attacked
attack_flag_x = cell(1,Ns);
attack_flag_u = cell(1,Ns);
for i=1:Ns
    attack_flag_x{1,i} = zeros(1,t_max);
    attack_flag_u{1,i} = zeros(1,t_max);
end

xxd_ = zeros(dim*Ns,Len_sec);
xxd_true = zeros(dim,1);

%% Communication parameter
d_SC=1000; % feedback channel
d_SC_sec = d_SC*Ts/Tc;
d_CA=1000; % forward channel
d_CA_sec = d_CA*Ts/Tc;

%% System state
x=zeros(dim*Ns,t_max+1);
x_pred=zeros(dim*Ns,t_max+1);
u=zeros(Ns,t_max+d_CA);
u_pred=zeros(Ns,t_max+d_CA);

%% System output: voltage and current
V=zeros(Ns,t_max+1);
I=zeros(Ns,t_max+1);
V_pred=zeros(Ns,t_max+1);
I_pred=zeros(Ns,t_max+1);

pic_num = 1;

tic
%% ------------------------------------------------------------------------
%% ------------------------Local Droop Control-----------------------------
%% ------------------------------------------------------------------------
for t=1:t_droop
    % system update
    x(:,t+1) = A*x(:,t)+B*u(:,t)+B*kron(ones(Ns,1),Vref);
    for i=1:Ns 
        % system output
        V(i,t+1)=x(dim*(i-1)+1,t+1);
        I(i,t+1)=x(dim*(i-1)+2,t+1);
    end
end


%% ------------------------------------------------------------------------
%% ------------------Activate PFC-Based Secondary Control----------------------------
%% ------------------------------------------------------------------------

tic
for t=1+t_droop:t_max
    if mod(t,Tc/Ts)==1
        if t>=1+t_droop+d_SC
            x_dg = zeros(1,dim);
            %% data communication 
            for i=1:Ns
                x_dg = i+(i-1)*(dim-1):i+(i-1)*(dim-1)+dim-1; % index
                attack_flag_x{1,i}(t) = Consensus(attack_probability_x);
                xxd_true=x(x_dg,t-d_SC); % SCÑÓÊ±£¬ÊÕµ½ÑÓÊ±Êý¾Ý
                if attack_flag_x{1,i}(t)==0  % safe from attack
    %                 xxd=xxd_true;
                    xxd_(x_dg,t)=xxd_true;
                else % attacked                   
                    xxd_(x_dg,t)=xxd_true+Ax(x_dg)*sin(Omega*(t-d_SC));
                    
                end
            end
            xxd = xxd_(:,t);
            % end communication
            %% prediction, compensate for the time delays in SC and CA
            for k=1:d_SC+d_CA
                xxd=A*xxd+B*u(:,t-d_SC+k-1)+B*kron(ones(Ns,1),Vref);
            end
            x_pred(:,t+d_CA)=xxd;
            for i=1:Ns 
                % for the output of ith subsystem
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

    % System evolution
    x(:,t+1) = A*x(:,t)+B*u(:,t)+B*kron(ones(Ns,1),Vref);
    for i=1:Ns 
        % for the output of ith subsystem
        V(i,t+1)=x(dim*(i-1)+1,t+1);
        I(i,t+1)=x(dim*(i-1)+2,t+1);
    end
    
    if mod(t,Steps_dis)==1
        disp(['run time = ', num2str((t-1)*Ts)]);
    end
    if mod(t,Steps_fig)==1
        f = figure(1);
        subplot(2,1,1),plot(V(:,1:t)'),axis([0,t_max,0,50]),legend('V1','V2','V3','V4','V5');
        xlabel('step'),ylabel('V'),title('output voltages');
        subplot(2,1,2),plot(I(:,1:t)'),axis([0,t_max,0,6]),legend('I1','I2','I3','I4','I5');
        xlabel('step'),ylabel('A'),title('output currents');
        drawnow
        F=getframe(gcf);
        img=frame2im(F);
        [img,map]=rgb2ind(img,256);
        if pic_num == 1
            imwrite(img,map,'MicrogridOutput.gif','gif','Loopcount',inf,'DelayTime',0.05);
        else
            imwrite(img,map,'MicrogridOutput.gif','gif','WriteMode','append','DelayTime',0.05);
        end
        pic_num = pic_num + 1;
    end
end

%% Plot
% t=1:t_max;
% figure(1);
% subplot(2,1,1),plot(t,V(1,t),t,V(2,t),t,V(3,t),t,V(4,t),t,V(5,t));
% legend('V1','V2','V3','V4','V5')
% subplot(2,1,2),plot(t,I(1,t),t,I(2,t),t,I(3,t),t,I(4,t),t,I(5,t));
% legend('I1','I2','I3','I4','I5')



%%
run_time=toc;
% save 'RunResult.mat' x xxd_ u u_pred V I Ts Tc...
%     Ax Au Omega attack_flag_u attack_flag_x t_max Len_sec run_time



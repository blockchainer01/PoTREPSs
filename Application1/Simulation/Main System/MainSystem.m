clear 

run('Initialize.m');
load('cons.mat');
load('result_strategy.mat');
tmax=20/Ts;  % run time
t_droop=5/Ts; % droop time

% define system variables
x=cell(1,Ns); % real state
u=cell(1,Ns);
u_att=cell(1,Ns);
x_hat=cell(1,Ns); % nominal state
u_hat=cell(1,Ns);
x_til=cell(1,Ns); % predicted state
x_til_att=cell(Ns,Ns);
x_til_pred=cell(Ns,Ns);

% define game variables
% set the posibilities of being attacked different on each communication
state_x=cell(Ns,Ns);
state_u=cell(1,Ns);
system_action_x=cell(Ns,Ns);
system_action_u=cell(1,Ns);
% 0/1 indicates whether the corresponding node is activated
% 0-the delegate is not selected
% 1-the delegate is selected
% 2-the optimal value is found among the delegates
% -1-the delegate has defected
attacker_action_x=cell(Ns,Ns);
attacker_action_u=cell(1,Ns);
% 0/1 indicates whether the corresponding node is attacked
action_sys_x=cell(Ns,Ns);  % action code
action_sys_u=cell(1,Ns);
action_att_x=cell(Ns,Ns);  % action code
action_att_u=cell(1,Ns);
attack_flag_x=cell(Ns,Ns);
attack_flag_u=cell(1,Ns);
% =1, if false data is transmitted
continue_attack_x=cell(Ns,Ns);
continue_attack_u=cell(1,Ns);

for i=1:Ns
    state_u{1,i}=zeros(1,tmax);
    system_action_u{1,i}=zeros(7,tmax);
    attacker_action_u{1,i}=zeros(7,tmax);
    action_sys_u{1,i}=zeros(1,tmax);
    action_att_u{1,i}=zeros(1,tmax);
    attack_flag_u{1,i}=zeros(1,tmax);
    continue_attack_u{1,i}=zeros(1,tmax);
    for j=1:Ns
        if A_comm(i,j)>0
            state_x{i,j}=zeros(1,tmax);
            system_action_x{i,j}=zeros(7,tmax);
            attacker_action_x{i,j}=zeros(7,tmax);
            action_sys_x{i,j}=zeros(1,tmax);
            action_att_x{i,j}=zeros(1,tmax);
            attack_flag_x{i,j}=zeros(1,tmax);
            continue_attack_x{i,j}=zeros(1,tmax);
        end
    end
end

%% strategies in game
system_strategy_x=cell(Ns,Ns);
attacker_strategy_x=cell(Ns,Ns);
M_x=cell(Ns,Ns);
all_choose_x=cell(Ns,Ns);
system_strategy_u=cell(1,Ns);
attacker_strategy_u=cell(1,Ns);
M_u=cell(1,Ns);
all_choose_u=cell(1,Ns);

for i=1:Ns
    % used for testing-choose all
    % system_strategy_u{1,i}=system_strategy_all;
    % attacker_strategy_u{1,i}=attacker_strategy_all;
    % used for testing-best strategy
    system_strategy_u{1,i}=system_strategy_best;
    attacker_strategy_u{1,i}=attacker_strategy_best;
    attack_probability=zeros(1,7);
    for n=1:7
        % attacked and successful
        attack_probability(n)=pa_u{1,i}(n)/ps_u{1,i}(n);
    end
    [M_u{1,i},all_choose_u{1,i}] = MM4(attack_probability);
    for j=1:Ns
        if A_comm(i,j)>0
            % all nodes participate in PBFT
            system_strategy_x{i,j}=system_strategy_all;
            % used for testing-choose all
            % attacker_strategy_x{i,j}=attacker_strategy_all;
            % used for testing-stochastic strategy
            attacker_strategy_x{i,j}=attacker_strategy_stoc;
            attack_probability=zeros(1,7);
            % attacked and successful
            for n=1:7
                attack_probability(n)=pa_x{i,j}(n)/ps_x{i,j}(n);
            end
            [M_x{i,j},all_choose_x{i,j}] = MM4(attack_probability);
        end
    end
end

V=zeros(Ns,tmax+1);
I=zeros(Ns,tmax+1);

for i=1:Ns
    x{1,i}=zeros(6,tmax+1);
    u{1,i}=zeros(1,tmax);
end
% 
% tic
% optimizer configuration
SoTimeLit=0.05;
ops=cell(1,7);
dis=0;
%1 cplex
ops{1,1}=sdpsettings('verbose',dis,'solver','cplex');
ops{1,1}.cplex.timelimit=SoTimeLit;

ops{1,2}=sdpsettings('verbose',dis,'solver','cplex');
ops{1,2}.cplex.timelimit=SoTimeLit;
ops{1,2}.cplex.barrier.convergetol=1e-3;

% %2 qpoases
% ops=sdpsettings('verbose',1,'solver','qpoases');
% ops.qpoases.maxCpuTime=0.0005;
% ops.qpoases.terminationTolerance=1e-1;
% ops.qpoases.boundTolerance=1e-1;
% ops.qpoases.maxIter=1000;

% %3 gurobi
ops{1,3}=sdpsettings('verbose',dis,'solver','gurobi');
ops{1,3}.gurobi.TimeLimit=SoTimeLit;
% ops.gurobi.OptimalityTol=1e-2;
% ops.gurobi.FeasibilityTol=1e-8;
% ops.gurobi.IterationLimit=5;
% ops.gurobi.BarIterLimit=10;
% ops.gurobi.Presolve=2;
% ops.gurobi.Threads=8;

% %4 quadprog
% for i=1:7
%     ops{1,i}=sdpsettings('verbose',dis,'solver','quadprog');
% end
% ops.quadprog.MaxIter=10;
% ops.quadprog.TolX=1e-1;
% ops=sdpsettings('verbose',0);
% diftime_opt=toc;

% %5 Xpress
ops{1,4}=sdpsettings('verbose',dis,'solver','xpress');
ops{1,4}.xpress.TIMELIMIT=SoTimeLit;

ops{1,5}=sdpsettings('verbose',dis,'solver','cplex');
ops{1,5}.cplex.timelimit=SoTimeLit;
ops{1,5}.cplex.barrier.convergetol=1e-9;

% %6 mosek
% ops=sdpsettings('verbose',1,'solver','mosek');

% %7 copt
ops{1,6}=sdpsettings('verbose',dis,'solver','copt');
ops{1,6}.copt.TimeLimit=SoTimeLit;

% ops{1,7}=sdpsettings('verbose',dis,'solver','copt');
% % ops{1,7}.copt.TimeLimit=SoTimeLit;
% ops{1,7}.copt.FeasTol=1e-3;

ops{1,7}=sdpsettings('verbose',dis,'solver','mosek');
ops{1,7}.mosek.MSK_DPAR_OPTIMIZER_MAX_TIME=SoTimeLit;

score=cell(1,Ns);
for i=1:Ns
    score{1,i}=0.99*ones(7,tmax);
end

pic_num = 1;

tic
%% ------------------------------------------------------------------------
%% ------------------------Local Droop Control-----------------------------
%% ------------------------------------------------------------------------
for t=1:t_droop
    % for ith subsystem
    for i=1:Ns
        if t==1
            u{1,i}(t)=V_ref;
        else
            u{1,i}(t)=0;
        end
        sum_xj=zeros(4,1);
        for j=1:Ns
            if A_com_p(i,j)>0
                sum_xj=sum_xj+A{i,j}(1:4,1:4)*x{1,j}(1:4,t);
            end
        end
        x{1,i}(1:4,t+1) = A{i,i}(1:4,1:4)*x{1,i}(1:4,t)+B{i,i}(1:4)*u{1,i}(t)+sum_xj;
        x{1,i}(5:6,t+1) = zeros(2,1);
        V(i,t+1)=V(i,t)+x{1,i}(1,t+1);
        I(i,t+1)=I(i,t)+I_max(i)*x{1,i}(2,t+1);
    end
    if mod(t,Steps_dis)==1
        disp(['run time = ', num2str((t-1)*Ts)]);
    end
    if mod(t,Steps_fig)==1
        f = figure(1);
        subplot(2,1,1),plot(V(:,1:t)'),axis([0,tmax,0,50]),legend('V1','V2','V3','V4','V5');
        xlabel('step'),ylabel('V'),title('output voltages');
        subplot(2,1,2),plot(I(:,1:t)'),axis([0,tmax,0,6]),legend('I1','I2','I3','I4','I5');
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

%% ------------------------------------------------------------------------
%% ------------------Activate Secondary Control----------------------------
%% ------------------------------------------------------------------------
%% first: calculate initial value
sum_I=zeros(1,Ns);
for i=1:Ns
    x{1,i}(5,t_droop+1) = V_ref-V(i,t_droop+1);
    for j=1:Ns
        if A_comm(i,j)>0
            sum_I(i)=sum_I(i)+I(j,t_droop+1)/I_max(j)-I(i,t_droop+1)/I_max(i);
        end
    end
    x{1,i}(6,t_droop+1) = sum_I(i);
end
% % basic secondary control and system evolution for testing
% for t=t_droop+1:tmax
%     t
%     for i=1:Ns
%         i
%         u{1,i}(t)=K{i,i}*x{1,i}(:,t);
%         sum_xj=zeros(6,1);
%         for j=1:Ns
%             if A_com_p(i,j)>0
%                 sum_xj=sum_xj+A{i,j}*x{1,j}(:,t);
%             end
%         end
%         x{1,i}(:,t+1) = A{i,i}*x{1,i}(:,t)+B{i,i}*u{1,i}(t)+sum_xj;
%         V(i,t+1)=V(i,t)+x{1,i}(1,t+1);
%         I(i,t+1)=I(i,t)+I_max(i)*x{1,i}(2,t+1);
%     end
% end


%% second: define variables needed for optimization
for i=1:Ns
    x_hat{1,i}=zeros(6,tmax+1);
    u_hat{1,i}=zeros(1,tmax);
    x_til{1,i}=zeros(6,tmax+N);
    for j=1:Ns
        if A_comm(i,j)>0
            % attacked information
            x_til_att{i,j}=zeros(6,tmax+N);
        end
    end
    % these variables are updated from the moment t_droop+1

    % create initial prediction sequence ready to send to neighbors
    for k=1:N
        x_til{1,i}(:,t_droop+k)=(Ac{i,i}+Bc{i,i}*K{i,i})^(k-1)*x{1,i}(:,t_droop+1);
    end
end

%% third: system interaction, computation and evolution
for t=t_droop+1:tmax
    % for ith subsystem
    for i=1:Ns
        % prediction and communication
        for j=1:Ns
            if A_comm(i,j)>0
                % whether or not attacked determined by game
                state_x{i,j}(t)=1;
                [system_action_x{i,j}(:,t),attacker_action_x{i,j}(:,t),action_sys_x{i,j}(t),...
                    action_att_x{i,j}(t),attack_flag_x{i,j}(t)] = ...
                    Game(state_x{i,j}(t),system_strategy_x{i,j},attacker_strategy_x{i,j},...
                    M_x{i,j},all_choose_x{i,j});
                % if safe from attack
                if attack_flag_x{i,j}(t)==0
                    if t==t_droop+1
                        for k=1:N
                            x_til_att{i,j}(:,t_droop+k)=x_til{1,j}(:,t_droop+k);
                        end
                    else
                        x_til_att{i,j}(:,t+N-1)=x_til{1,j}(:,t+N-1);
                    end
                    continue_attack_x{i,j}(t)=0;
                % else being attacked
                else
                    if t==t_droop+1
                        for k=1:N
                            x_til_att{i,j}(:,t_droop+k)=x_til{1,j}(:,t_droop+k)+Ay*sin(Omega*(t_droop+k));
                        end
                        continue_attack_x{i,j}(t)=1;
                    else
                        x_til_att{i,j}(:,t+N-1)=x_til{1,j}(:,t+N-1)+Ay*sin(Omega*(t+N-1));
                        continue_attack_x{i,j}(t)=continue_attack_x{i,j}(t-1)+1;
                    end
                end
            end
        end

        % compensate for delays using predicted values
        % if it's the first step, no value is available
        if t<=t_droop+N_delay_comm
            for j=1:Ns
                if A_comm(i,j)>0
                    x_til_pred{i,j}=zeros(6,N);
                end
            end
        % there is value available for the follow-up
        else
            for j=1:Ns
                if A_comm(i,j)>0
                    x_til_pred{i,j}=x_til_att{i,j}(:,t:t+N-1-N_delay_comm);
                    for k=1:N_delay_comm
                        x_til_pred{i,j}=[x_til_pred{i,j},x_til_att{i,j}(:,t+N-1-N_delay_comm)];
                    end
                end
            end
        end
        % for j=1:Ns
        %     if A_comm(i,j)>0
        %         x_til_pred{i,j}=x_til_att{i,j}(:,t:t+N-1-N_delay_comm);
        %         for k=1:N_delay_comm
        %             x_til_pred{i,j}=[x_til_pred{i,j},x_til_att{i,j}(:,t+N-1-N_delay_comm)];
        %         end
        %     end
        % end

        % electoral delegations utilize game
        state_u{1,i}(t)=GetState(x{1,i}(:,t),state_rank);
        [system_action_u{1,i}(:,t),attacker_action_u{1,i}(:,t),action_sys_u{1,i}(t),...
            action_att_u{1,i}(t),attack_flag_u{1,i}(t)] = ...
            Game(state_u{1,i}(t),system_strategy_u{1,i},attacker_strategy_u{1,i},...
            M_u{1,i},all_choose_u{1,i});

        % optimization problem
        % only delegates participate in solving and submit results
        if mod(t,Steps_con)==1
        % creating decision variables
        x_pred_node=cell(1,7);
        u_pred_node=cell(1,7);
        costF_node=cell(1,7);
        % use smart contract to weed out agents that chronically fail to solve on demand
        for node=1:7
            if score{1,i}(node,t)<=1e-2
                system_action_u{1,i}(node,t)=0;
            end
            if system_action_u{1,i}(node,t)==1
                % tic
                yalmip('clear')
                x_pred=sdpvar(6,N+1);
                u_pred=sdpvar(1,N);
                
                % add constraints
                Con=[];
                % 1. about dynamics
                for k=1:N
                    sum_xj=zeros(6,N);
                    for j=1:Ns
                        if A_comm(i,j)>0
                            % sum_xj(:,k)=sum_xj(:,k)+Ac{i,j}*x_til_att{i,j}(:,t+k-1);
                            sum_xj(:,k)=sum_xj(:,k)+Ac{i,j}*x_til_pred{i,j}(:,k);
                        end
                    end
                    Con=[Con;
                        x_pred(:,k+1) == Ac{i,i}*x_pred(:,k)+Bc{i,i}*u_pred(k)+sum_xj(:,k)];
                end
                % 2. about H
                Con=[Con;
                    H{1,i}*(x{1,i}(:,t)-x_pred(:,1)) <= 1*h{1,i} ];
                % 3. about E
                for k=1:N
                    Con=[Con;
                        E{1,i}*(x_pred(:,k)-x_til{1,i}(:,t+k-1)) <= 1*e{1,i} ];
                end
                % 4. about the prediction of trajectory
                for k=1:N
                    Con=[Con;
                        xb{1,i}(:,1) <= x_pred(:,k);
                        x_pred(:,k) <= xb{1,i}(:,2) ];
                end
                % 5. about the prediction of control input
                for k=1:N
                    Con=[Con;
                        ub{1,i}(1) <= u_pred(k);
                        u_pred(k) <= ub{1,i}(2)];
                end
                % 6. terminal constraints
                Con=[Con;
                    xFb{1,i}(:,1) <= x_pred(:,N+1);
                    x_pred(:,N+1) <= xFb{1,i}(:,2) ];
                % diftime_con=toc
                %
                % tic
                % cost function
                z=x_pred(:,N+1)'*P{1,i}*x_pred(:,N+1);
                for k=1:N
                    z=z+x_pred(:,k)'*Q{1,i}*x_pred(:,k);
                    z=z+u_pred(k)'*R{1,i}*u_pred(k);
                end

                % solve
                % diftime_fun=toc
                % diftime=toc;

                % tic
                result=optimize(Con,z,ops{1,node});
                % diftime_solve=toc
                if result.problem==0
                    % represents a successful solution
                    % value(x_pred)
                    % value(z)
                else
                    disp(['solve error: ',num2str(i),',',num2str(node)]);
                end
                x_pred_node{1,node}=value(x_pred);
                u_pred_node{1,node}=value(u_pred);
                costF_node{1,node}=value(z);
                % modelOpTime=result.yalmiptime;  % time for Yalmip building
                % searchOpTime=result.solvertime;  % time for solving
            end
        end

        % among the elected delegations
        % verification session
        node_best=0;
        for node=1:7
            if system_action_u{1,i}(node,t)==1
                % add constraints
                Con_veri=[];
                % 1. about dynamics
                for k=1:N
                    sum_xj=zeros(6,N);
                    for j=1:Ns
                        if A_comm(i,j)>0
                            % sum_xj(:,k)=sum_xj(:,k)+Ac{i,j}*x_til_att{i,j}(:,t+k-1);
                            sum_xj(:,k)=sum_xj(:,k)+Ac{i,j}*x_til_pred{i,j}(:,k);
                        end
                    end
                    for kk=1:size(x_pred_node{1,node},1)
                        x_pred_veri=Ac{i,i}(kk,:)*x_pred_node{1,node}(:,k)...
                            +Bc{i,i}(kk,:)*u_pred_node{1,node}(k)+sum_xj(kk,k);
                        if x_pred_node{1,node}(kk,k+1)<0
                            Con_veri=[Con_veri;
                                1.01*x_pred_node{1,node}(kk,k+1) <= x_pred_veri;
                                x_pred_veri <= 0.99*x_pred_node{1,node}(kk,k+1)];
                        else
                            Con_veri=[Con_veri;
                                0.99*x_pred_node{1,node}(kk,k+1) <= x_pred_veri;
                                x_pred_veri <= 1.01*x_pred_node{1,node}(kk,k+1)];
                        end
                    end
                end
                % 2. about H
                Con_veri=[Con_veri;
                    H{1,i}*(x{1,i}(:,t)-x_pred_node{1,node}(:,1)) <= 1*h{1,i} ];
                % 3. about E
                for k=1:N
                    Con_veri=[Con_veri;
                        E{1,i}*(x_pred_node{1,node}(:,k)-x_til{1,i}(:,t+k-1)) <= 1*e{1,i} ];
                end
                % 4. about the prediction of trajectory
                for k=1:N
                    Con_veri=[Con_veri;
                        xb{1,i}(:,1) <= x_pred_node{1,node}(:,k);
                        x_pred_node{1,node}(:,k)<= xb{1,i}(:,2) ];
                end
                % 5. about the prediction of control input
                for k=1:N
                    Con_veri=[Con_veri;
                        ub{1,i}(1) <= u_pred_node{1,node}(k);
                        u_pred_node{1,node}(k) <= ub{1,i}(2) ];
                end
                % 6. terminal constraints
                Con_veri=[Con_veri;
                    xFb{1,i}(:,1) <= x_pred_node{1,node}(:,N+1);
                    x_pred_node{1,node}(:,N+1) <= xFb{1,i}(:,2) ];


                % size(Con_veri,1)
                % size(find(Con_veri==0),1)
                
                if size(find(Con_veri==0),1)~=0
                    % direct recording if conditions are not met
                    system_action_u{1,i}(node,t)=-1;
                    score{1,i}(node,t)=(score{1,i}(node,t-1))^1.4;
                else
                    % meet the conditions to participate in the comparison
                    score{1,i}(node,t)=score{1,i}(node,t-1);
                    % selected and performe normally
                    if node_best==0
                        % if is the first solution that satisfies the condition
                        % assign to best
                        node_best=node;
                    elseif costF_node{1,node}<costF_node{1,node_best}
                        % smaller than the current optimal cost function
                        % replace the current node with the optimal
                        node_best=node;
                    end
                    % No action if currently satisfied but not better than others
                end
            else
                % unchecked, keep score
                score{1,i}(node,t)=score{1,i}(node,t-1);
            end
        end
        
        % tic
        if node_best==0
            % if nodes 1 to 7 are traversed and there is no working
            % delay of one step
            u{1,i}(t)=u{1,i}(t-1);
        else
            x_pred_best=x_pred_node{1,node_best};
            u_pred_best=u_pred_node{1,node_best};
            system_action_u{1,i}(node_best,t)=2;
            u{1,i}(t)=u_pred_best(1)+K{i,i}*(x{1,i}(:,t)-x_pred_best(:,1));
        end

        for k=1:Steps_con
            % get the control signal in one control cycle
            u{1,i}(t+k-1)=u{1,i}(t);
            x_hat{1,i}(:,t+k-1)=x_pred_best(:,1);
        end
        if t==t_droop+1
            x_til{1,i}(:,t+N)=x_pred_best(:,N+1);
        else
            for k=1:Steps_con
                x_til{1,i}(:,t+N-(k-1))=x_pred_best(:,N+1);
            end
        end
        end

        % diftime_con=toc
        % 
        % tic

        if attack_flag_u{1,i}(t)==0  % safe from attack
            u_att{1,i}(t)=u{1,i}(t);
            continue_attack_u{1,i}(t)=0;
        else % attacked
            u_att{1,i}(t)=u{1,i}(t)+Au*sin(Omega*(t));
            if t==t_droop+1
                continue_attack_u{1,i}(t)=1;
            else
                continue_attack_u{1,i}(t)=continue_attack_u{1,i}(t-1)+1;
            end
        end

        sum_xj=zeros(6,1);
        for j=1:Ns
            if A_com_p(i,j)>0
                sum_xj=sum_xj+A{i,j}*x{1,j}(:,t);
            end
        end
        x{1,i}(:,t+1) = A{i,i}*x{1,i}(:,t)+B{i,i}*u_att{1,i}(t)+sum_xj;
        % itetime=toc;
        V(i,t+1)=V(i,t)+x{1,i}(1,t+1);
        I(i,t+1)=I(i,t)+I_max(i)*x{1,i}(2,t+1);
    end
    if mod(t,Steps_dis)==1
        disp(['run time = ', num2str((t-1)*Ts)]);
    end
    if mod(t,Steps_fig)==1
        f = figure(1);
        subplot(2,1,1),plot(V(:,1:t)'),axis([0,tmax,0,50]),legend('V1','V2','V3','V4','V5');
        xlabel('step'),ylabel('V'),title('output voltages');
        subplot(2,1,2),plot(I(:,1:t)'),axis([0,tmax,0,6]),legend('I1','I2','I3','I4','I5');
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
run_time=toc;
save 'RunResult.mat' x x_hat x_til x_til_att u u_att V I system_action_u state_u...
    Ay Au Omega attack_flag_u attack_flag_x tmax t_droop run_time
%% plot
load('RunResult.mat');
% 1. state evolution of subsystems respectively
t=1:tmax;
figure;
subplot(3,1,1),plot(t,x{1,1}(1,t),t,x{1,1}(2,t),t,x{1,1}(3,t),t,x{1,1}(4,t));
legend('x1','x2','x3','x4')
subplot(3,1,2),plot(t,x{1,2}(1,t),t,x{1,2}(2,t),t,x{1,2}(3,t),t,x{1,2}(4,t));
legend('x1','x2','x3','x4')
subplot(3,1,3),plot(t,x{1,3}(1,t),t,x{1,3}(2,t),t,x{1,3}(3,t),t,x{1,3}(4,t));
legend('x1','x2','x3','x4')

% 2. control signal of subsystems respectively
t=1:tmax;
figure;
plot(t,u{1,1}(t),t,u{1,2}(t),t,u{1,3}(t));
legend('u1','u2','u3')

% 3. outputs for each area
t=1:tmax;
figure;
subplot(3,1,1),plot(t,df(1,t),t,df(2,t),t,df(3,t));
legend('df1','df2','df3')
subplot(3,1,2),plot(t,dP(1,t),t,dP(2,t),t,dP(3,t));
legend('dP1','dP2','dP3')
subplot(3,1,3),plot(t,ACE(1,t),t,ACE(2,t),t,ACE(3,t));
legend('ACE1','ACE2','ACE3')

% 4. injected false data
figure
t=1:Steps_con:tmax;
plot(t,Ay*sin(Omega*t),t,Au*sin(Omega*t));
legend('Ay','Au')

% 5. attacks happened on control signals and system states
figure
t=1:Steps_con:tmax;
x_scaplot=kron(ones(1,9),t');
y_scaplot=[9*attack_flag_u{1,1}(t);8*attack_flag_u{1,2}(t);7*attack_flag_u{1,3}(t);
    6*attack_flag_x{1,3}(t);5*attack_flag_x{1,2}(t);
    4*attack_flag_x{2,1}(t);3*attack_flag_x{2,3}(t);
    2*attack_flag_x{3,2}(t);1*attack_flag_x{3,1}(t)]';
scatter(x_scaplot,y_scaplot,12,'filled');

% 6. frequency statistics of unsuccessful defense against attacks
t=1:Steps_con:tmax;
att_freq=zeros(1,9);
att_freq(1)=sum(attack_flag_u{1,1}(t))/size(t,2);
att_freq(2)=sum(attack_flag_u{1,2}(t))/size(t,2);
att_freq(3)=sum(attack_flag_u{1,3}(t))/size(t,2);
att_freq(4)=sum(attack_flag_x{1,3}(t))/size(t,2);
att_freq(5)=sum(attack_flag_x{1,2}(t))/size(t,2);
att_freq(6)=sum(attack_flag_x{2,1}(t))/size(t,2);
att_freq(7)=sum(attack_flag_x{2,3}(t))/size(t,2);
att_freq(8)=sum(attack_flag_x{3,2}(t))/size(t,2);
att_freq(9)=sum(attack_flag_x{3,1}(t))/size(t,2);

% 7. signals before and after FDIA
t=1:Steps_con:tmax;
figure
subplot(3,1,1),plot(t,u_att{1,1}(t),t,u{1,1}(t))
legend('u-att','u')
subplot(3,1,2),plot(t,x_til_att{1,3}(1,t),t,x_til{1,3}(1,t))
legend('x-til1-att','x-til1')
subplot(3,1,3),plot(t,x_til_att{1,3}(4,t),t,x_til{1,3}(4,t))
legend('x-til4-att','x-til4')

% 8. comparison of each state variable with predicted and optimized values
t=1:tmax;
figure;
subplot(2,4,1),plot(t,x{1,1}(1,t),t,x_til{1,1}(1,t),t,x_hat{1,1}(1,t)),legend('x','xt','xh');
subplot(2,4,2),plot(t,x{1,1}(2,t),t,x_til{1,1}(2,t),t,x_hat{1,1}(2,t)),legend('x','xt','xh');
subplot(2,4,3),plot(t,x{1,1}(3,t),t,x_til{1,1}(3,t),t,x_hat{1,1}(3,t)),legend('x','xt','xh');
subplot(2,4,4),plot(t,x{1,1}(4,t),t,x_til{1,1}(4,t),t,x_hat{1,1}(4,t)),legend('x','xt','xh');
subplot(2,4,5),plot(t,x{1,2}(1,t),t,x_til{1,2}(1,t),t,x_hat{1,2}(1,t)),legend('x','xt','xh');
subplot(2,4,6),plot(t,x{1,2}(2,t),t,x_til{1,2}(2,t),t,x_hat{1,2}(2,t)),legend('x','xt','xh');
subplot(2,4,7),plot(t,x{1,2}(3,t),t,x_til{1,2}(3,t),t,x_hat{1,2}(3,t)),legend('x','xt','xh');
subplot(2,4,8),plot(t,x{1,2}(4,t),t,x_til{1,2}(4,t),t,x_hat{1,2}(4,t)),legend('x','xt','xh');

% 9. statistics on the performance of each optimizer
score_best=zeros(Ns,7);
for i=1:Ns
    for node=1:7
        score_best(i,node)=size(find(system_action_u{1,i}(node,1:Steps_con:tmax)==2),2);
    end
end

score_n=zeros(Ns,7);
for i=1:Ns
    for node=1:7
        score_n(i,node)=size(find(system_action_u{1,i}(node,1:Steps_con:tmax)==-1),2);
    end
end

t=1:Steps_con:tmax;
figure
plot(t,score{1,1}(:,t),t,score{1,2}(:,t),t,score{1,3}(:,t))

% 10. game state
figure
plot([state_u{1,1};state_u{1,2};state_u{1,3}]')

% 11. run time
run_time



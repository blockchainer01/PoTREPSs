%% plot
load('RunResult.mat');
% 1. state evolution of subsystems respectively
t=1:tmax;
figure;
subplot(5,1,1),plot(t,x{1,1}(1,t),t,x{1,1}(2,t),t,x{1,1}(3,t),t,x{1,1}(4,t),t,x{1,1}(5,t),t,x{1,1}(6,t));
legend('x1','x2','x3','x4','x5','x6')
subplot(5,1,2),plot(t,x{1,2}(1,t),t,x{1,2}(2,t),t,x{1,2}(3,t),t,x{1,2}(4,t),t,x{1,2}(5,t),t,x{1,2}(6,t));
legend('x1','x2','x3','x4','x5','x6')
subplot(5,1,3),plot(t,x{1,3}(1,t),t,x{1,3}(2,t),t,x{1,3}(3,t),t,x{1,3}(4,t),t,x{1,3}(5,t),t,x{1,3}(6,t));
legend('x1','x2','x3','x4','x5','x6')
subplot(5,1,4),plot(t,x{1,4}(1,t),t,x{1,4}(2,t),t,x{1,4}(3,t),t,x{1,4}(4,t),t,x{1,4}(5,t),t,x{1,4}(6,t));
legend('x1','x2','x3','x4','x5','x6')
subplot(5,1,5),plot(t,x{1,5}(1,t),t,x{1,5}(2,t),t,x{1,5}(3,t),t,x{1,5}(4,t),t,x{1,5}(5,t),t,x{1,5}(6,t));
legend('x1','x2','x3','x4','x5','x6')

% 2. control signal of subsystems respectively
t=1:tmax;
figure;
plot(t,u{1,1}(t),t,u{1,2}(t),t,u{1,3}(t),t,x{1,4}(t),t,u{1,5}(t));
legend('u1','u2','u3','u4','u5')

% 3. voltage and current outputs for each DG
t=1:tmax;
figure;
subplot(2,1,1),plot(t,V(1,t),t,V(2,t),t,V(3,t),t,V(4,t),t,V(5,t));
legend('V1','V2','V3','V4','V5')
subplot(2,1,2),plot(t,I(1,t),t,I(2,t),t,I(3,t),t,I(4,t),t,I(5,t));
legend('I1','I2','I3','I4','I5')

% 4. injected false data
figure
t=t_droop+1:tmax;
plot(t,Ay*sin(Omega*t),t,Au*sin(Omega*t));
legend('Ay','Au')

% 5. attacks happened on control signals and system states
figure
t=t_droop+1:tmax;
x_scaplot=kron(ones(1,15),t');
y_scaplot=[15*attack_flag_u{1,1}(t);14*attack_flag_u{1,2}(t);13*attack_flag_u{1,3}(t);
    12*attack_flag_u{1,4}(t);11*attack_flag_u{1,5}(t);
    10*attack_flag_x{1,5}(t);9*attack_flag_x{1,2}(t);
    8*attack_flag_x{2,1}(t);7*attack_flag_x{2,3}(t);
    6*attack_flag_x{3,2}(t);5*attack_flag_x{3,4}(t);
    4*attack_flag_x{4,3}(t);3*attack_flag_x{4,5}(t);
    2*attack_flag_x{5,4}(t);1*attack_flag_x{5,1}(t)]';
scatter(x_scaplot,y_scaplot,12,'filled');

% 6. frequency statistics of unsuccessful defense against attacks
att_freq=zeros(1,15);
att_freq(1)=sum(attack_flag_u{1,1}(t))/(tmax-t_droop);
att_freq(2)=sum(attack_flag_u{1,2}(t))/(tmax-t_droop);
att_freq(3)=sum(attack_flag_u{1,3}(t))/(tmax-t_droop);
att_freq(4)=sum(attack_flag_u{1,4}(t))/(tmax-t_droop);
att_freq(5)=sum(attack_flag_u{1,5}(t))/(tmax-t_droop);
att_freq(6)=sum(attack_flag_x{1,5}(t))/(tmax-t_droop);
att_freq(7)=sum(attack_flag_x{1,2}(t))/(tmax-t_droop);
att_freq(8)=sum(attack_flag_x{2,1}(t))/(tmax-t_droop);
att_freq(9)=sum(attack_flag_x{2,3}(t))/(tmax-t_droop);
att_freq(10)=sum(attack_flag_x{3,2}(t))/(tmax-t_droop);
att_freq(11)=sum(attack_flag_x{3,4}(t))/(tmax-t_droop);
att_freq(12)=sum(attack_flag_x{4,3}(t))/(tmax-t_droop);
att_freq(13)=sum(attack_flag_x{4,5}(t))/(tmax-t_droop);
att_freq(14)=sum(attack_flag_x{5,4}(t))/(tmax-t_droop);
att_freq(15)=sum(attack_flag_x{5,1}(t))/(tmax-t_droop);

% 7. signals before and after FDIA
t=t_droop+1:tmax;
delta=zeros(1,tmax);
delta_att=zeros(1,tmax);
for k=t_droop+1:tmax
    delta(k)=delta_att(k-1)+u{1,1}(k);
    delta_att(k)=delta_att(k-1)+u_att{1,1}(k);
end
figure
subplot(3,1,1),plot(t,delta_att(t),t,delta(t))
legend('delta-att','delta')
subplot(3,1,2),plot(t,x_til_att{1,2}(5,t),t,x_til{1,2}(5,t))
legend('x-til5-att','x-til5')
subplot(3,1,3),plot(t,x_til_att{1,2}(6,t),t,x_til{1,2}(6,t))
legend('x-til6-att','x-til6')

% 8. comparison of each state variable with predicted and optimized values
figure;
subplot(2,6,1),plot(t,x{1,1}(1,t),t,x_til{1,1}(1,t),t,x_hat{1,1}(1,t)),legend('x','xt','xh');
subplot(2,6,2),plot(t,x{1,1}(2,t),t,x_til{1,1}(2,t),t,x_hat{1,1}(2,t)),legend('x','xt','xh');
subplot(2,6,3),plot(t,x{1,1}(3,t),t,x_til{1,1}(3,t),t,x_hat{1,1}(3,t)),legend('x','xt','xh');
subplot(2,6,4),plot(t,x{1,1}(4,t),t,x_til{1,1}(4,t),t,x_hat{1,1}(4,t)),legend('x','xt','xh');
subplot(2,6,5),plot(t,x{1,1}(5,t),t,x_til{1,1}(5,t),t,x_hat{1,1}(5,t)),legend('x','xt','xh');
subplot(2,6,6),plot(t,x{1,1}(6,t),t,x_til{1,1}(6,t),t,x_hat{1,1}(6,t)),legend('x','xt','xh');
subplot(2,6,7),plot(t,x{1,2}(1,t),t,x_til{1,2}(1,t),t,x_hat{1,2}(1,t)),legend('x','xt','xh');
subplot(2,6,8),plot(t,x{1,2}(2,t),t,x_til{1,2}(2,t),t,x_hat{1,2}(2,t)),legend('x','xt','xh');
subplot(2,6,9),plot(t,x{1,2}(3,t),t,x_til{1,2}(3,t),t,x_hat{1,2}(3,t)),legend('x','xt','xh');
subplot(2,6,10),plot(t,x{1,2}(4,t),t,x_til{1,2}(4,t),t,x_hat{1,2}(4,t)),legend('x','xt','xh');
subplot(2,6,11),plot(t,x{1,2}(5,t),t,x_til{1,2}(5,t),t,x_hat{1,2}(5,t)),legend('x','xt','xh');
subplot(2,6,12),plot(t,x{1,2}(6,t),t,x_til{1,2}(6,t),t,x_hat{1,2}(6,t)),legend('x','xt','xh');

% 9. statistics on the performance of each optimizer
score_best=zeros(Ns,7);
for i=1:Ns
    for node=1:7
        score_best(i,node)=size(find(system_action_u{1,i}(node,t_droop+1:tmax)==2),2);
    end
end

score_n=zeros(Ns,7);
for i=1:Ns
    for node=1:7
        score_n(i,node)=size(find(system_action_u{1,i}(node,t_droop+1:tmax)==-1),2);
    end
end

% 10. game state
figure
plot([state_u{1,1};state_u{1,2};state_u{1,3};state_u{1,4};state_u{1,5}]')

% 11. run time
run_time



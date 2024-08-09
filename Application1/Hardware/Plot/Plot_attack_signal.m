clear
%%
load("RunResult1.mat");
Ts=1e-4;
tmax=20/Ts;  % run time
t_droop=5/Ts; % droop time
Steps_con=500; 

Au=0.1; % magnitude of the attack on the control signal
Omega=0.1; % angular frequency
att_all=[];
att_u=[];
for t=t_droop+1:Steps_con:tmax
    att_all=[att_all,Au*sin(Omega*(t))];
    att_u=[att_u,attack_flag_u{1,1}(t)*Au*sin(Omega*(t))];
end

%%
figure(6)
set(groot,'defaultAxesTickLabelInterpreter','latex');  
set(groot,'defaulttextinterpreter','latex');
set(groot,'defaultLegendInterpreter','latex');
height=700;
width=127/72*height;
left=100;
bottem=100;
set(gcf,'position',[left,bottem,width,height])

% pp(1)=stem(att_all','.','MarkerSize',2);
% hold on
% pp(2)=stem(att_u','-.','MarkerSize',2);
% hold off
pp(1)=stem((1:300)*15/300+5,att_all','MarkerSize',0.5);
hold on
pp(2)=stem((1:300)*15/300+5,att_u','MarkerSize',0.5);
hold off

% set(pp(1),'LineStyle','-'); 
% set(pp(2),'LineStyle','-.'); 
co1=[0.4118    0.6706    0.6196];
co2='b';
set(pp,{'Color'},{co1;co2},{'LineStyle'},{'-';'-.'}); 

set(pp(1),'LineWidth',1) 
set(pp(2),'LineWidth',3) 

ylim([-0.12,0.11]);

h= legend ({ 'Original attak signal', 'Attak signal after PoT consensus'},'Interpreter','latex','Location','southeast','FontSize', 13);
set(h,'Orientation','horizon')

xlabel({'Time (s)'},'Interpreter','latex', 'FontSize', 12);
ylabel({'Attack performance on $u_1$'},'Interpreter','latex', 'FontSize', 15);


grid on
set(gca,'gridlinestyle',':','linewidth',1)


%% save fig
ax = gca;
copygraphics(ax,'Resolution',1000)




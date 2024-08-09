clear
%% All attack flags are plotted
%% Plot frequent attack
%%
load("RunResult1.mat");
Ts=1e-4;
tmax=20/Ts;  % run time
t_droop=5/Ts; % droop time
Steps_con=500; 

%% 2.攻击发生的情况
x_scaplot=[];
y_scaplot=[];
tt=1;
for t=t_droop+1:Steps_con:tmax
    x_scaplot=[x_scaplot;tt*ones(1,15)];
    y_scaplot=[y_scaplot;
        15*attack_flag_u{1,1}(t),14*attack_flag_u{1,2}(t),13*attack_flag_u{1,3}(t),...
        12*attack_flag_u{1,4}(t),11*attack_flag_u{1,5}(t),...
        10*attack_flag_x{1,5}(t),9*attack_flag_x{1,2}(t),...
        8*attack_flag_x{2,1}(t),7*attack_flag_x{2,3}(t),...
        6*attack_flag_x{3,2}(t),5*attack_flag_x{3,4}(t),...
        4*attack_flag_x{4,3}(t),3*attack_flag_x{4,5}(t),...
        2*attack_flag_x{5,4}(t),1*attack_flag_x{5,1}(t)];
    tt=tt+1;
end
% size(x_scaplot)
% size(y_scaplot)

figure(4)
set(groot,'defaultAxesTickLabelInterpreter','latex');  
set(groot,'defaulttextinterpreter','latex');
set(groot,'defaultLegendInterpreter','latex');
height=700;%高度 62
width=127/72*height;%宽度，像素数127
left=100;%距屏幕左下角水平距离
bottem=100;%距屏幕左下角垂直距离
set(gcf,'position',[left,bottem,width,height])

% scatter(x_scaplot(:,1)*15/300+5,y_scaplot(:,1),10,'filled');
% hold on;
for i=1:15
    y_scaplot(:,i) = y_scaplot(:,i)*3;
    for j=1:length(y_scaplot(:,i))
        if y_scaplot(j,i)==0
            y_scaplot(j,i)=(15-i+1)*3-1;
        end
    end
%     scatter(x_scaplot(:,i)*15/300+5,y_scaplot(:,i)*2,18,'filled');
    scatter(x_scaplot(:,i)*15/300+5,y_scaplot(:,i),12,'filled');
    hold on;
end

for i=1:15
    pp(i)=plot((1:300)*15/300+5,i*3*ones(1,300));
    hold on;
end
hold off;
grid on
set(gca,'gridlinestyle',':','linewidth',1)
% set(pp,'Color','#B4B4B8','LineStyle','-.') %设置颜色和线宽
set(pp,'Color','#DDDDDD','LineStyle','-.') %设置颜色和线宽

ylim([0,46]);
set(pp,'LineWidth',0.2)

% legend('u1','u2','u3','u4','u5','x15','x12','x21','x23','x32','x34','x43','x45','x54','x51')
yticks(0:46);
% yticklabels({'Noun','$x_{51}$','$x_{54}$','$x_{45}$','$x_{43}$','$x_{34}$','$x_{32}$','$x_{23}$','$x_{21}$',...
%     '$x_{12}$','$x_{15}$',...
%     '$u_5$','$u_4$','$u_3$','$u_2$','$u_1$',''});
yticklabels({'','','','$x_{51}$','','','$x_{54}$','','','$x_{45}$','','','$x_{43}$','','','$x_{34}$',...
    '','','$x_{32}$','','','$x_{23}$','','','$x_{21}$',...
    '','','$x_{12}$','','','$x_{15}$',...
    '','','$u_5$','','','$u_4$','','','$u_3$','','','$u_2$','','','$u_1$',''});
set(gca,'FontSize',10,'Fontname','Times New Roman');
xlabel({'Time (s)'},'Interpreter','latex', 'FontSize', 12);
ylabel({'Attack times on all 15 signals'},'Interpreter','latex', 'FontSize', 15);



%% save fig
ax = gca;
copygraphics(ax,'Resolution',1000)



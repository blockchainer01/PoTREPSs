clear
%%
Ts=1e-4;
tmax=20/Ts;  % run time
t_droop=5/Ts; % droop time
Steps_con=500; 
repeat=20;
Ay=[0,0,0,0,1,0.1]'; % magnitude of the attack on the state
Au=0.1; % magnitude of the attack on the control signal
Omega=0.1; % angular frequency

%% 1.compute probability
attack_all=5*300*ones(3,repeat);
attack_true=zeros(3,repeat);

%% 2.Jtask
Jtask=zeros(3,repeat);
Vref=48;
I_max = [1 1 1.8 1.8 1.8];

%% 3. Halpha
Halpha=zeros(3,repeat);

for k=1:repeat
    for method=1:3
        if method==1
            filename=['RunResult',num2str(k),'.mat'];
        elseif method==2
            filename=['RunResultComA',num2str(k),'.mat'];
        else
            filename=['RunResultComB',num2str(k),'.mat'];
        end
        load(filename);
        Vmax=zeros(1,5);
        Imax=zeros(1,5);
        Umax=zeros(1,5);
        U=zeros(5,tmax);
        for i=1:5
            Vmax(i)=max(V(i,:));
            Imax(i)=max(I(i,:));
            for t=t_droop+1:tmax
                U(i,t)=U(i,t-1)+u_att{1,i}(t);
            end
            Umax(i)=max(U(i,:));
        end

        for t=t_droop+1:Steps_con:tmax
            %% 1.
            if attack_flag_u{1,1}(t)==1 || attack_flag_x{1,5}(t)==1 || attack_flag_x{1,2}(t)==1
                attack_true(method,k)=attack_true(method,k)+1;
            end
            if attack_flag_u{1,2}(t)==1 || attack_flag_x{2,1}(t)==1 || attack_flag_x{2,3}(t)==1
                attack_true(method,k)=attack_true(method,k)+1;
            end
            if attack_flag_u{1,3}(t)==1 || attack_flag_x{3,2}(t)==1 || attack_flag_x{3,4}(t)==1
                attack_true(method,k)=attack_true(method,k)+1;
            end
            if attack_flag_u{1,4}(t)==1 || attack_flag_x{4,3}(t)==1 || attack_flag_x{4,5}(t)==1
                attack_true(method,k)=attack_true(method,k)+1;
            end
            if attack_flag_u{1,5}(t)==1 || attack_flag_x{5,4}(t)==1 || attack_flag_x{5,1}(t)==1
                attack_true(method,k)=attack_true(method,k)+1;
            end
            %% 2.
            for i=1:5
                Jtask(method,k)=Jtask(method,k)+abs(x{1,i}(5,t)/Vmax(i))+abs(x{1,i}(6,t)/(Imax(i)/I_max(i)));
            end
            %% 3.
            Halpha(method,k)=Halpha(method,k)...
                +attack_flag_x{1,5}(t)*abs(Ay(5)*sin(Omega*t)/Vmax(5)) ...
                +attack_flag_x{1,5}(t)*abs(Ay(6)*sin(Omega*t)/(Imax(5)/I_max(5))) ...
                +attack_flag_x{1,2}(t)*abs(Ay(5)*sin(Omega*t)/Vmax(2)) ...
                +attack_flag_x{1,2}(t)*abs(Ay(6)*sin(Omega*t)/(Imax(2)/I_max(2))) ...
                +attack_flag_u{1,1}(t)*abs(Au*sin(Omega*t)/Umax(1)) ...
                +attack_flag_x{2,1}(t)*abs(Ay(5)*sin(Omega*t)/Vmax(1)) ...
                +attack_flag_x{2,1}(t)*abs(Ay(6)*sin(Omega*t)/(Imax(1)/I_max(1))) ...
                +attack_flag_x{2,3}(t)*abs(Ay(5)*sin(Omega*t)/Vmax(3)) ...
                +attack_flag_x{2,3}(t)*abs(Ay(6)*sin(Omega*t)/(Imax(3)/I_max(3))) ...
                +attack_flag_u{1,2}(t)*abs(Au*sin(Omega*t)/Umax(2)) ...
                +attack_flag_x{3,2}(t)*abs(Ay(5)*sin(Omega*t)/Vmax(2)) ...
                +attack_flag_x{3,2}(t)*abs(Ay(6)*sin(Omega*t)/(Imax(2)/I_max(2))) ...
                +attack_flag_x{3,4}(t)*abs(Ay(5)*sin(Omega*t)/Vmax(4)) ...
                +attack_flag_x{3,4}(t)*abs(Ay(6)*sin(Omega*t)/(Imax(4)/I_max(4))) ...
                +attack_flag_u{1,3}(t)*abs(Au*sin(Omega*t)/Umax(3)) ...
                +attack_flag_x{4,3}(t)*abs(Ay(5)*sin(Omega*t)/Vmax(3)) ...
                +attack_flag_x{4,3}(t)*abs(Ay(6)*sin(Omega*t)/(Imax(3)/I_max(3))) ...
                +attack_flag_x{4,5}(t)*abs(Ay(5)*sin(Omega*t)/Vmax(5)) ...
                +attack_flag_x{4,5}(t)*abs(Ay(6)*sin(Omega*t)/(Imax(5)/I_max(5))) ...
                +attack_flag_u{1,4}(t)*abs(Au*sin(Omega*t)/Umax(4)) ...
                +attack_flag_x{5,4}(t)*abs(Ay(5)*sin(Omega*t)/Vmax(4)) ...
                +attack_flag_x{5,4}(t)*abs(Ay(6)*sin(Omega*t)/(Imax(4)/I_max(4))) ...
                +attack_flag_x{5,1}(t)*abs(Ay(5)*sin(Omega*t)/Vmax(1)) ...
                +attack_flag_x{5,1}(t)*abs(Ay(6)*sin(Omega*t)/(Imax(1)/I_max(1))) ...
                +attack_flag_u{1,5}(t)*abs(Au*sin(Omega*t)/Umax(5));
        end
    end
end
safe=attack_all-attack_true;
safe_pro=safe./attack_all;
attack_pro=attack_all./attack_all;



%% Plot ratio
c0 = [17,47,65]/255;
c1 = [6,133,135]/255;
c2 = [79,185,159]/255;
c3 = [242,177,52]/255;
c4 = [237,85,59]/255;
figure
bb1=bar(attack_pro(1,:),1); 
hold on
bb2=bar(safe_pro(1,:),1); 
% axis([-inf inf 60 100])
width=4*400;  
height=1.2*400;  
left=200;  
bottem=200;
set(gcf,'position',[left,bottem,width,height])

bb1.FaceColor = c3;
bb2.FaceColor = [126, 87, 194]/255;


%% Jtask
figure
boxplot([Jtask(1,:)',Jtask(2,:)',Jtask(3,:)']);
% set(gca,'linewidth',1.5)
xlabel('Control Method');
ylabel('Jtask');
xticklabels({'PoT','Existing method 1','Existing method 2'})

%% Halpha
figure
boxplot([Halpha(1,:)',Halpha(2,:)',Halpha(3,:)']);
% set(gca,'linewidth',1.5)
xlabel('Control Method');
ylabel('Halpha');
xticklabels({'PoT','Existing method 1','Existing method 2'})

%%

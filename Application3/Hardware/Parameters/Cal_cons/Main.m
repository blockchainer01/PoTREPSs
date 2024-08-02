clear 
run('Initialize.m');

options_on = optimoptions('linprog','Display', 'final');
options_off = optimoptions('linprog','Display', 'off');

%% define prediction error
HH=cell(1,Ns);
hh=cell(1,Ns);
for i=1:Ns
    HH{1,i}=[1 0 0 0;
        -1 0 0 0;
        0 1 0 0;
        0 -1 0 0;
        0 0 1 0;
        0 0 -1 0;
        0 0 0 1;
        0 0 0 -1];
    hh{1,i}=0.5*[1; 1; 4; 4; 4; 4; 4; 4];
end

%% calculate system inaccuracies
WW=cell(1,Ns);
ww=cell(1,Ns);
for i=1:Ns
    con=0;
    temps1=[];temps2=[];
    for j=1:Ns
        if A_comm(i,j)>0
            [temp1,temp2]=constraintTransT(HH{1,j},hh{1,j},A{i,j});
            if con==0
                temps1=temp1;temps2=temp2;
            else
                [temps1,temps2]=MinkowskiSum(temps1,temps2,temp1,temp2,options_off);
            end
            con=1;
        end
    end
    WW{1,i}=temps1;
    ww{1,i}=temps2;
end

%% calculate RPI set Z
H=cell(1,Ns);
h=cell(1,Ns);
alpha = zeros(1,Ns);
AA=cell(1,Ns);
s=[200,200,200];
for i=1:Ns
    AA{1,i}=A{i,i}+B{i,i}*K{i,i};
    % s=5000;
    [H{1,i},h{1,i},alpha(i)]=mRPIs(AA{1,i},WW{1,i},ww{1,i},s(i),i,options_off);
end

%% set E
E=cell(1,Ns);
e=cell(1,Ns);
ZE=cell(1,Ns);
ze=cell(1,Ns);
for i=1:Ns
    E{1,i}=[1 0 0 0;
        -1 0 0 0;
        0 1 0 0;
        0 -1 0 0;
        0 0 1 0;
        0 0 -1 0;
        0 0 0 1;
        0 0 0 -1];
    e{1,i}=20*[0.2; 0.2; 0.005; 0.005; 0.0001; 0.0001; 0.04; 0.04];
    [ZE{1,i},ze{1,i}]=MinkowskiSum(H{1,i},h{1,i},E{1,i},e{1,i},options_off);
end

save 'cons.mat' H h E e


function [flag] = Consensus(attack_probability)
% calculate matrix M
% attack_probability should be known
% need to traverse the attacked node, the node sending data
% all_node=[1 2 3 4 5 6 7];
% choose5=nchoosek(all_node,5);
% choose6=nchoosek(all_node,6);
% choose7=nchoosek(all_node,7);


choose7=[1 1 1 1 1 1 1];
all_choose=choose7;


sys_choose=all_choose;
%     for att=1:29  
% the action of the attacker
att_choose=all_choose;
% for all sensor\attacker\controller_action(:,i)£¬
% corresponding probability of all scenes
% turn the above decided actions to the division of two kinds of nodes
% focus only on the channel with the message
% don't care if it is attacked or not
node_ASC=[];  % attacked and activated nodes
node_SC=[];  % nonattacked and activated nodes

% obtain these two kinds of nodes
for node=1:7
    if sys_choose(node)==1  % activated
        if att_choose(node)==1  % attacked
            node_ASC=[node_ASC,node];
        else  % nonattacked
            node_SC=[node_SC,node];
        end
    end
end

% the node that is not selected by the attacker but sends a message is ignored
% only the node that is selected by the attacker and sends a message
% creates uncertainty, and need to calculate the probability
pro_0=0;pro_1=0; % T/F
n_nosure=size(node_ASC,2);
n_all=2^n_nosure;  % number of cases
everypro=ones(n_all,1);  % corresponding probilities
for m=1:n_all  % every case
    % examine the probability and outcome corresponding to this attack scenario
    % add this probability to the total probability corresponding to the outcome
    b=dec2bin(m-1,n_nosure);  % if attack success
    flag0=size(node_SC,2);  % number of true message
    flag1=0;

    for l=1:n_nosure
        if b(l)=='1'
            everypro(m)=everypro(m)*attack_probability(node_ASC(l));
            flag1=flag1+1;
        else
            everypro(m)=everypro(m)*(1-attack_probability(node_ASC(l)));
            flag0=flag0+1;
        end
    end
    % result (0/1-T/F)
    if flag0>flag1
        pro_0=pro_0+everypro(m);
    elseif flag0<flag1
        pro_1=pro_1+everypro(m);
        everypro(m)=everypro(m)+1;
    else
        pro_0=pro_0+0.5*everypro(m);
        pro_1=pro_1+0.5*everypro(m);
    end
end
% M=pro_0;

select_state=rand(1);

% pro0=M;

if select_state<=pro_0
    flag=0;
else
    flag=1;
end


end


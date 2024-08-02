function [system_action,attacker_action,action_sys,action_att,flag] = Game(state_S,system_strategy,attacker_strategy,M,all_choose)
s=system_strategy(:,state_S);
a=attacker_strategy(:,state_S);

% 7 nodes to choose from, a total of 29 choices
s_sum=zeros(1,29);
for k=1:29
    for i=1:k
        s_sum(k)=s_sum(k)+s(i);
    end
end
% select action
select_action_system=rand(1);
for k=1:29
    if select_action_system<s_sum(k)
        action_sys=k;
        break
    end
    action_sys=29;
end
system_action=all_choose(action_sys,:)';

a_sum=zeros(1,29);
for k=1:29
    for i=1:k
        a_sum(k)=a_sum(k)+a(i);
    end
end
% select action
select_action_attacker=rand(1);
for k=1:29
    if select_action_attacker<a_sum(k)
        action_att=k;
        break
    end
    action_att=29;
end
attacker_action=all_choose(action_att,:)';
select_state=rand(1);
pro0=M(action_sys,action_att);
if select_state<=pro0
    flag=0;
else
    flag=1;
end


end


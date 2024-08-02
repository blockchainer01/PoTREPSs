function [state] = GetState(xx,state_rank)

yy=xx'*xx;
if yy<=state_rank(1)
    state=1;
elseif yy<=state_rank(2)
    state=2;
elseif yy<=state_rank(3)
    state=3;
elseif yy<=state_rank(4)
    state=4;
else
    state=5;
end
end


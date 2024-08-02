function [A,b] = removeRedundantConstraints(A,b)
% given a constrained set X={x| Ax<=b}
% remove redundant constraints and return  X={x| Ax<=b}

% remove same rows
[A,b] = conRegularization(A,b);
temp = [A b];
temp = unique(temp,'rows');
A = temp(:,1:end-1);
b = temp(:,end);


% if constraint Ai*x<=bi is redundant,
options = optimoptions('linprog','display','off');
for i = size(A,1):-1:1
    f = A(i,:);
    if f*f'<=10^-10   % remove zero rows
        A(i,:) = [];
        b(i,:) = [];
    else              % remove redundant rows
        [~,temp,flag]  = linprog( -A(i,:), A,b,[],[],[],[],options);
        temp = -temp;  % the maximal value of Ai*x
        if flag == -3    % Problem is unbounded.
            ;
        elseif temp - b(i)<=-10^(-4)  % the maximal value is less than bi
            A(i,:) = [];
            b(i)   = [];
        end
    end
end


function [A,b] = MinkowskiSum(A1,b1,A2,b2,options)
% given two sets: X1:{x|A1*x<=b1}, X2:{A2*x<=b2}
% obtain the Minkowski sum X={x1+x2| x1 in X1, x2 in X2}

A = [A1; A2];  b = [b1; b2];
for i = 1:size(A1,1)
    [~,temp] = linprog( -A1(i,:), A2,b2,[],[],[],[],options );
    if isempty(temp)
        temp = 0;
    end
    b(i) = b(i) - temp;
end

for i = 1:size(A2,1)
    [~,temp] = linprog( -A2(i,:), A1,b1,[],[],[],[],options );
    if isempty(temp)
        temp = 0;
    end
    b(i+size(A1,1)) = b(i+size(A1,1)) - temp;
end

% delete redundant constraints
[A,b] = removeRedundantConstraints(A,b);

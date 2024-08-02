function [A,b] = constraintTransT(A,b,T)
% given a set X define by X:{x|Ax<=b}
% obtain the transformed set Y=TX : {y=Tx|x in X}

% for the case of T singular
T(2:4,:)=[];
T(:,[3:4,6])=[];
A([5:8,11:12],:)=[];
b([5:8,11:12])=[];
A(:,[3:4,6])=[];
A = A*inv(T);
b = b;

A=[A(:,1),zeros(6,3),A(:,2:3)];
A=[A(1:2,:);
    [0 1 0 0 0 0];
    [0 -1 0 0 0 0];
    [0 0 1 0 0 0];
    [0 0 -1 0 0 0];
    [0 0 0 1 0 0];
    [0 0 0 -1 0 0];
    A(3:6,:)];
b=[b(1:2);
    10^(-8)*ones(6,1);
    b(3:6)];
[A,b] = removeRedundantConstraints(A,b);

end
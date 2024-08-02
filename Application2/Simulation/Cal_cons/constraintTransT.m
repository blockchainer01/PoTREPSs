function [A,b] = constraintTransT(A,b,T)
% given a set X define by X:{x|Ax<=b}
% obtain the transformed set Y=TX : {y=Tx|x in X}

% for the case of T singular
T(1:3,:)=[];
T(:,2:4)=[];
A(3:8,:)=[];
b(3:8)=[];
A(:,2:4)=[];
A = A*inv(T);
b = b;

A=[zeros(2,3),A(:,1)];
A=[ [1 0 0 0];
    [-1 0 0 0];
    [0 1 0 0];
    [0 -1 0 0];
    [0 0 1 0];
    [0 0 -1 0];
    A(1:2,:)];
% b=[b(1:2);
%     10^(-8);
%     10^(-6);
%     b(3:6)];
b=[ 0;
    0;
    0;
    0;
    0;
    0;
    b(1:2)];
[A,b] = removeRedundantConstraints(A,b);


end
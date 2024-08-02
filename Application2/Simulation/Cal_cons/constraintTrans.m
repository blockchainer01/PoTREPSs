function [A,b] = constraintTrans(A,b,T)
% given a set X define by X:{x|Ax<=b}
% obtain the transformed set Y=TX : {y=Tx|x in X}

% consider x=inv(T)*y, 
% then the constraints becomes A*inv(T)<=b

if size(T,2) == size(T,1)  % check if A is square
    if rank(T) == size(T,1)  % check if A is of full rank
        A = A*inv(T);
        b = b;
    else                    % A is singular
        [U,S,V]=svd(T);
        for n=1:size(S,1)
            if S(n,n)~=0
                S(n,n)=1/S(n,n);
            end
        end
        A = A*(V*S*U');
        b = b;
        [A,b] = removeRedundantConstraints(A,b);
    end
else                        % A is not a square matrix
    [U,S,V]=svd(T);
    S=S';
    for n=1:size(S,2)
        if S(n,n)~=0
            S(n,n)=1/S(n,n);
        end
    end
    A = A*(V*S*U');
    b = b;
    [A,b] = removeRedundantConstraints(A,b);

end
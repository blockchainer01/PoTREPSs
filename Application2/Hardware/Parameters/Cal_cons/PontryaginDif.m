function [A,b] = PontryaginDif(A1,b1,A2,b2)
% given two sets: X1:{x|A1*x<=b1}, X2:{A2*x<=b2}
% obtain the Pontryagin difference X={x| x oplus X2 in X1}

A = A1;  b = b1;

for i = 1:size(A,1)
    [~,temp] = linprog( -A(i,:), A2,b2 );
    b(i) = b(i) - (-temp);
end

[A,b] = removeRedundantConstraints(A,b);

end
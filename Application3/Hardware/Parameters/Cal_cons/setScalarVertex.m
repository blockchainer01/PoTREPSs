function [mu] = setScalarVertex(vertex1,vertex2)
% get the min mu such that vertex1 \subseteq mu vertex2
% X1, X2 in vertex expression

[C1 b1] = vert2lcon(vertex1);
[C2 b2] = vert2lcon(vertex2);
mu = setScalar(C1,b1,C2,b2);


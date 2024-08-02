function [X,figP,figL,V] = constraintVisualization(Oa,Ob)
%   draw a linear constrained set R2
%   constraints is Ax<=B
X = lcon2vert(Oa,Ob);

%%  plot the rigion
DT = delaunayTriangulation(X);
[C,V]  = convexHull(DT);

figP = plot(DT.Points(:,1),DT.Points(:,2),'.','MarkerSize',10);
hold on
figL = plot(DT.Points(C,1),DT.Points(C,2),'r');

end
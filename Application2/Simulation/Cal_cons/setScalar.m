function [mu] = setScalar(C1,b1,C2,b2)
% get the min mu such that X1 \subseteq mu X2
% X1, X2 in vertex expression
% insipred by 2019-[automatica]-Robust MPC with recursive model update
% T*C1 = C2, T*b1<=b2*mu

N1 = size(C1,1);
N2 = size(C2,1);

Ceq = kron(C1',eye(N2));
Ceq = [0*Ceq(:,1)  Ceq];
beq = C2(:);

Cieq = kron(b1',eye(N2));
Cieq = [-b2 Cieq];
bieq = Cieq(:,1)*0;

Cieq = [Cieq; [zeros(N1*N2,1)  -eye(N1*N2)]];
bieq = [bieq; zeros(N1*N2,1)];

f = [ones(1,1); zeros(N1*N2,1)];

temp = linprog(f,Cieq,bieq,Ceq,beq);
mu = temp(1);

% options = optimoptions('linprog','Display', 'off');
% alpha = 0;
% for i=1:size(C2,1)
%     fi = C2(i,:);
%     gi = b2(i,:);
%     [~,temp] = linprog(-fi,C1,b1,[],[],[],[]);
%     temp = -temp;
%     if gi~=0
%     temp = temp/gi;
%     if temp>alpha
%         alpha = temp;
%     end
%     end
% end
% 
% mu=alpha;

end


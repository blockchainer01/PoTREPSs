clear all
%% circuit specifications
Ts= 0.0001; % simulation step
Ns=5;  % number of subsystems
dim=4; % dimension of system model
U_in = [100 80 80 100 120]; % voltage source

% RLC filters
R_t = 0*[0.5 0.2 0.2 0.5 0.5];
L_t = 2e-3*ones(1,Ns);
C_t = 2000*1e-6*ones(1,Ns);

% tie lines
R_ij=zeros(Ns,Ns);
L_ij=zeros(Ns,Ns);
R_ij(1,2) = 0.5;  % L_ij(1,2) = 50e-6;  
R_ij(2,3) = 1;    % L_ij(2,3) = 100e-6;
R_ij(3,4) = 0.2;  % L_ij(3,4) = 50e-6;
R_ij(4,5) = 0.6;  % L_ij(4,5) = 50e-6;
R_ij(5,1) = 0.8;  % L_ij(5,1) = 80e-6;
R_ij(2,4) = 0.5; R_ij(4,2) = R_ij(2,4); 
R_ij(2,5) = 0.3; R_ij(5,2) = R_ij(2,5); 
R_ij(1,4) = 0.1; R_ij(4,1) = R_ij(1,4); 

R_ij(2,1) = R_ij(1,2); L_ij(2,1) = L_ij(1,2);
R_ij(3,2) = R_ij(2,3); L_ij(3,2) = L_ij(2,3);
R_ij(4,3) = R_ij(3,4); L_ij(4,3) = L_ij(3,4);
R_ij(5,4) = R_ij(4,5); L_ij(5,4) = L_ij(4,5);
R_ij(1,5) = R_ij(5,1); L_ij(1,5) = L_ij(5,1);

% loads
R_L = 1*[10 10 13 10 10];

%% Inner control loops
kp_inner_I = 0.07*ones(1,Ns); % Out, voltage
ki_inner_I = 1*ones(1,Ns);
kp_inner_II = 0.01*ones(1,Ns); % In, current
ki_inner_II = 1*ones(1,Ns);

%%
I_max = [1 1 1.8 1.8 1.8];
Rd = [1.9 1.9 0.9 1 1.02];
V_ref=48;

%% 
A = cell(Ns,Ns);
B = cell(Ns,Ns);
D = cell(Ns,Ns);

%% continous model
for i=1:Ns
    A{i,i}=zeros(dim,dim);
    B{i,i}=zeros(dim,1);
    D{i,i}=zeros(dim,1);
    % Aii Bii Cii
    temp1=0;
    temp2=0;
    for k=1:Ns
        if R_ij(i,k)~=0
            temp1 = temp1 +1/( R_ij(i,k)*C_t(i) );
            temp2 = temp2 + 1/R_ij(i,k);
        end
    end
    eta=1/R_L(i)+temp2;
    A{i,i}(1,1) = -1/C_t(i)/R_L(i)-temp1;
    A{i,i}(1,2) = 1/C_t(i);
    A{i,i}(2,1) = -1/L_t(i)*(1+U_in(i)*kp_inner_II(i)*kp_inner_I(i)*(1+Rd(i)*eta));
    A{i,i}(2,2) = -R_t(i)/L_t(i)-U_in(i)/L_t(i)*kp_inner_II(i);
    A{i,i}(2,3) = U_in(i)/L_t(i)*kp_inner_II(i)*ki_inner_I(i);
    A{i,i}(2,4) = U_in(i)/L_t(i)*ki_inner_II(i);
    A{i,i}(3,1) = -1-Rd(i)*eta;
    A{i,i}(4,1) = -kp_inner_I(i)*(1+Rd(i)*eta);
    A{i,i}(4,2) = -1;
    A{i,i}(4,3) = ki_inner_I(i);
    B{i,i}(2) = U_in(i)/L_t(i)*kp_inner_II(i)*kp_inner_I(i);
    B{i,i}(3) = 1;
    B{i,i}(4) = kp_inner_I(i);
    D{i,i} = B{i,i};
    % Aij Bij Cij
    for j=1:Ns
        if j~=i
            A{i,j} = zeros(dim,dim);
            B{i,j} = zeros(dim,1);
            D{i,j} = zeros(dim,1);
            if R_ij(i,j)~=0 
                A{i,j}(1,1) = 1/( C_t(i)*R_ij(i,j) );
                A{i,j}(2,1) = (U_in(i)*kp_inner_II(i)*kp_inner_I(i)*Rd(i))/L_t(i)/R_ij(i,j);
                A{i,j}(3,1) = Rd(i)/R_ij(i,j);
                A{i,j}(4,1) = Rd(i)*kp_inner_I(i)/R_ij(i,j);
            end
        end
    end
end

%% Global system
A_all=cell2mat(A);
B_all=cell2mat(B);
D_all=cell2mat(D);
% [A_all,B_all]=c2d(A_all,[B_all,D_all],Tc);
% for i=1:Ns
%     for j=1:Ns
%         A{i,j}=A_all((i-1)*dim+1:i*dim,(j-1)*dim+1:j*dim);
%         B{i,j}=B_all((i-1)*dim+1:i*dim,(j-1)*2+1);
%         D{i,j}=B_all((i-1)*dim+1:i*dim,j*2);
%     end
% end

%% discrete model used in node
% [A_all,B_all]=c2d(A_all,B_all,Tc);
A_all=Ts*A_all+eye(Ns*dim);
B_all=Ts*B_all;
for i=1:Ns
    for j=1:Ns
        A{i,j}=A_all((i-1)*dim+1:i*dim,(j-1)*dim+1:j*dim);
        B{i,j}=B_all((i-1)*dim+1:i*dim,j);
    end
end

%%
save A_all 
save B_all



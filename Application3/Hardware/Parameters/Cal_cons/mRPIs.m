function [H,h,alpha] = mRPIs(AA,Wc,W,s,numb,options)
% given system x+ = Ax + w, w in W:{Wc*w <= W}
% given iteration step s
% provide the outer approximation of 
% minimal robust positively invariant set X:{Hx<=h}

%% obtain sum A^i*W
H = Wc;
h = W;
for i=1:(s-1)
    [H,h] = constraintTrans(H,h,AA);
    [H,h] = MinkowskiSum(Wc,W,H,h,options);
    % Omit some constraints
    H_now=[H,h];
    k=1; % kth cycle
    n=0; % How many have been deleted
    while k+n<size(H,1) % Check the remaining constraints
        N=size(H_now,1); % Number of constraints remaining
        % Taking the kth constraint as the benchmark
        H_base=H_now(k,:);
        l=k+1;
        for step=k+1:N
            H_test=H_now(l,:); % lth constraint
            H_test=[H_base;H_test];
            if size(H,1)<100
                rankH=rank(H_test,1e-3); % Adjustable precision
            else
                rankH=rank(H_test,1e-1);
            end
            if rankH==2 % linear irrelevance
                l=l+1; % check the next one
            else % linear correlation 
                H_now(l,:)=[]; % delete it
                n=n+1; % Number of deletions
            end
        end
        k=k+1;
    end
    H = H_now(:,1:4);
    h = H_now(:,5);
    disp([numb,i]);
end

[H,h] = removeRedundantConstraints(H,h);


%% obtain alpha
alpha = 0;
As    = AA^s;
for i=1:size(W,1)
    fi = Wc(i,:);       fi = As'*fi';   fi = fi';
    gi = W(i,:);
    [~,temp] = linprog(-fi,Wc,W,[],[],[],[]);
    temp = -temp;
    if gi~=0
    temp = temp/gi;
    if temp>alpha
        alpha = temp;
    end
    end
end
alpha


%% output
H = H;
h = h/(1-alpha);

end
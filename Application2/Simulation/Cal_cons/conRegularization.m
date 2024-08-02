function [A,b] = conRegularization(A,b)
for i=1:size(A,1)
    fi = A(i,:);
    gi = b(i);

    while fi*fi'>10^10
        fi=fi./10;
        gi=gi./10;
    end
    while fi*fi'<10^(-10)
        fi=fi.*10;
        gi=gi.*10;
    end

    A(i,:) = fi;
    b(i) = gi;
end
end


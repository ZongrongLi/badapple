%��˹�˺���
function gau_res=Gaus(sig)
n=3*sig+1;%����ģ���С
nc=floor((n+1)/2);%����ģ������
for i=1:n
    for j=1:n
       gau_res(i,j)=exp(-((i-nc)^2 + (j-nc)^2)/(2*sig)^2);
    end;
end;
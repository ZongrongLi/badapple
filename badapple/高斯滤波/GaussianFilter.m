function image=GaussianFilter(image1)
%��ͼ��image1���и�˹ƽ��
%�����õ�����һά�ĸ�˹��
%����ƽ�����ͼ��
image1=im2double(image1);
[p,q]=size(image1);
image=zeros(p,q);
%---------------------------------------------
%������˹ģ��
alf=0.5;
n=7;
n1=floor((n+1)/2);%ȷ������
for i=1:n
   x(i)= exp(-((i-n1)^2)/(2*alf^2));
   y(i)= exp(-((i-n1)^2)/(2*alf^2));
end
%----------------------------------------------
%����ƽ��
for m=1:p
   a=image1(m,:);
   a1=conv(a,x);
  image(m,:)=a1(fix((n-1)/2)+1:fix((n-1)/2)+q);
end
%----------------------------------------------
%����ƽ��
for k=1:q-10
    b=image1(:,k);
    b1=conv(b,y);
    image(:,n)=b1(fix((n-1)/2)+1:fix((n-1)/2)+p);
end




    
    
function image=GaussianFilter(image1)
%对图像image1进行高斯平滑
%其中用到两个一维的高斯核
%返回平滑后的图像
image1=im2double(image1);
[p,q]=size(image1);
image=zeros(p,q);
%---------------------------------------------
%产生高斯模板
alf=0.5;
n=7;
n1=floor((n+1)/2);%确定中心
for i=1:n
   x(i)= exp(-((i-n1)^2)/(2*alf^2));
   y(i)= exp(-((i-n1)^2)/(2*alf^2));
end
%----------------------------------------------
%横向平滑
for m=1:p
   a=image1(m,:);
   a1=conv(a,x);
  image(m,:)=a1(fix((n-1)/2)+1:fix((n-1)/2)+q);
end
%----------------------------------------------
%纵向平滑
for k=1:q-10
    b=image1(:,k);
    b1=conv(b,y);
    image(:,n)=b1(fix((n-1)/2)+1:fix((n-1)/2)+p);
end




    
    
function image1=GaussianPyramid(image1,n)
%����image1��n��Gaussian������
clf;
for k=1:n
    clf;
    image1=GaussianFilter(image1);
end
 
    
    
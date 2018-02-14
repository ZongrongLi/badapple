function image1=GaussianPyramid(image1,n)
%产生image1的n级Gaussian金字塔
clf;
for k=1:n
    clf;
    image1=GaussianFilter(image1);
end
 
    
    
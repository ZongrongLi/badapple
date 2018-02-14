
i=imread('des\\B2538.bmp'); %��ȡͼ��




i=rgb2gray(i);
j=GaussianPyramid(i,5);
j=mat2gray(j);
[m,n]=size(j);
para=0.85;
for x=1:m
    for y=1:n
        if j(x,y)<para
            j(x,y)=0;
        elseif j(x,y)>=para
            j(x,y)=1;
        end
    end
end
imwrite(j,'B2538.bmp');

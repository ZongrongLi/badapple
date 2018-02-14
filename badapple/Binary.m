i=imread('test.BMP');
subplot(1,2,1);
imshow(i);
i=rgb2gray(i);
[m,n]=size(i);
for x=1:m
    for y=1:n
        if i(x,y)<128
            i(x,y)=0;
        elseif i(x,y)>=128
            i(x,y)=255;
        end
    end
end
%imwrite(i,'./test1.BMP');
subplot(1,2,2);
imshow(i);

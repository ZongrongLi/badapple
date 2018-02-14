for b=1:10
str=num2str(b);
str1=['table\\C',str,'.bmp'];
i=imread(str1);
[m,n]=size(i);
n=n/3;
for x=2:m-1
    for y=2:n-1
       if i(x,y,1)==255
           continue;
       end
       if i(x,y-1,1)==255 &&i(x,y+1,1)==255&&i(x+1,y,1)==255&&i(x-1,y,1)==255
           i(x,y,1)=255;
           i(x,y,2)=255;
           i(x,y,3)=255;
       end
    end
end
str2=['table\\D',str,'.bmp'];
imwrite(i,str2);
end
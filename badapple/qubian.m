for b=5431:5472;
str=num2str(b);
if b<10
 str=['B000',str,'.BMP'];
elseif b<100
    str=['B00',str,'.BMP'];
elseif b<1000
    str=['B0',str,'.BMP'];
elseif b<10000
    str=['B',str,'.BMP'];
end
str

str1=['des2\\',str];
i=imread(str1);


[m,n]=size(i);
 for x=1:m
     i(x,2,1)=i(x,5,1);
     i(x,2,2)=i(x,5,2);
     i(x,2,3)=i(x,5,3);
     i(x,369,1)=i(x,366,1);
     i(x,369,2)=i(x,366,2);
     i(x,369,3)=i(x,366,3);
      i(x,3,1)=i(x,5,1);
     i(x,3,2)=i(x,5,2);
     i(x,3,3)=i(x,5,3);
     i(x,368,1)=i(x,366,1);
     i(x,368,2)=i(x,366,2);
     i(x,368,3)=i(x,366,3);
 end

imwrite(i,str1);
end

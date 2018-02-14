for b=1:5472;
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
n=n/3;
for x=1:m
    for y=1:n
        if x>=136&&x<=141
            i(x,y,1)=255;
            i(x,y,2)=255;
            i(x,y,3)=255;
        end
         if y>=183&&y<=187
              i(x,y,1)=255;
            i(x,y,2)=255;
            i(x,y,3)=255;
         end
    end
end
    str2=['des3\\',str];
imwrite(i,str2);
end
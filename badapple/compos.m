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
str1=['hehe\\',str];
str2=['des1\\',str];

i=imread(str1);
j=imread(str2);
new=imread('SPACE.BMP');
[m,n]=size(j);
for x=1:m
    for y=1:n
        if j(x,y)<10
            new(x,y,1)=24;
            new(x,y,2)=129;
            new(x,y,3)=189;
        elseif j(x,y)>253
            if i(x,y,1)>250
            new(x,y,1)=255;
            new(x,y,2)=255;
            new(x,y,3)=255;
            elseif i(x,y,1)<25
            new(x,y,1)=241;
            new(x,y,2)=246;
            new(x,y,3)=250;
            else
            new(x,y,1)=241;
            new(x,y,2)=246;
            new(x,y,3)=250;
            end
        else
            new(x,y,1)=241;
            new(x,y,2)=246;
            new(x,y,3)=250;
        end
    end
end
str3=['des2\\',str];
imwrite(new,str3);
end
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
ps=imread(str1); %¶ÁÈ¡Í¼Ïñ
pa=rgb2gray(ps);
pa = edge(pa,'sobel');
[m,n]=size(pa);
M=zeros(m,n);
for i=1:m
    for j=1:n
        if(pa(i,j)==1)
         ps(i,j,1)=24 ;
         ps(i,j,2)=129;
         ps(i,j,3)=189;
        elseif(pa(i,j)==0)
         ps(i,j,1)=255 ;
         ps(i,j,2)=255;
         ps(i,j,3)=255;
        end
    end
end
 
 str2=['des\\',str];
imwrite(ps,str2);
end

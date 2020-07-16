I=[];


f= imread('//filelocation');
f=rgb2gray(f);
%f=imresize(f,[300,300],'bilinear');
[m,n]=size(f);
subplot(1,2,1);imshow(f);title('jerry training image');
temp=reshape(f',m*n,1);
I=[I temp];



g= imread('//filelocation');
g=rgb2gray(g);
%g=imresize(g,[300,300],'bilinear');
[m,n]=size(g);
subplot(1,2,2);imshow(g);title('tom training image');
temp=reshape(g',m*n,1);
I=[I temp];



%m1= mean(I,2);
ima=reshape(m1',n,m);
ima=ima';
figure,imshow(ima);title('mean');


for i=1:2
  temp=double(I(:,i));
  I1(:,i)=(temp-m1);
end


for i=1:2
  %subplot(ceil(sqrt(2)),ceil(sqrt(2),i);
  imagg1=reshape(I1(:,i),n,m);
  imagg1=imagg1';
  [m n]=size(imagg1);
  %imshow(imagg1);
  subplot(1,2,i);imshow(imagg1);title('mean subtracted values');
end




a1=[];
for i=1:2
  te=double(I1(:,i));
  a1=[a1,te];
end

a=a1';
covv=a*a';

[eigenvec,eigenvalue]=eig(covv);


d=eig(covv);


sorteigen=[];
eigval=[];
for i=1:size(eigenvec,2)
  if(d(i)>(0.5e+008))
    sorteigen=[sorteigen,eigenvec(:,i)];
    eigval=[eigval,eigenvalue(i,i)];
   end
  end

  
  eigenfaces=[];
  eigenfaces=eigenfaces=a1*sorteigen;
  
 for i=1:size(sorteigen,2)
    k=sorteigen(:,i);
    tem=sqrt(sum(k.^2));
    sorteigen(:,i)=sorteigen(:,i)./tem;
  end
  
  
  eigenfaces=a1*sorteigen;
  
  for i=1:size(eigenfaces,2)
    ima=reshape(eigenfaces(:,i)',n,m);
    ima=ima'
   figure(4),subplot(1,2,i);imshow(ima);title('eigen faces');
    end
 

  
  projectedimage=[];
  for i=1:2
    projectedimage=eigenfaces'*I1;
  end

  %disp(projectedimage);
 
  inputimage=imread('//TestImgLocation');
  inputimage=rgb2gray(inputimage);
  figure(5),subplot(1,2,1);imshow(inputimage);title('test image');
    
  inputimagevector=reshape(inputimage,m*n,1);
  inputimagevector=double(inputimagevector);
  meaninputimage=inputimagevector-m1;
  projectedinputimage=eigenfaces'*meaninputimage;
  
  euclidendistance=[];
  for i=1:2
    temp=projectedimage(:,i)-projectedinputimage;
    euclidendistance=[euclidendistance temp];
  end
  
  [mineuclid,index]=min(temp);
  disp(mineuclid);
     if(mineuclid<1.6e008)
          disp('its a tom');
     elseif(mineuclid<1.9e008)
          disp('its a jerry');
     else 
          disp('its not a cartoon');
     end
  
  
  
  
  
  
  
  
  
  
  
  
  





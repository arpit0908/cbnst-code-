#include<stdio.h>
#include<math.h>
int main()
{
  float low , high ,  x[20],y[20],xn,s,h,d,p;// n- total no of values ,s = n in the formula y find = d, 
  int j,i,n;
  printf("enter the value of n :\n");
  scanf("%d",&n);
  printf("enter the elements of x:\n");
  for(i=1;i<=n;i++)
   {
    printf("x[%d]=",i);
    scanf("%f%f",&low , &high);
    x[i] = (low + high)/2;
   }
    printf("enter the elements of y:\n");
    for(i=1;i<=n;i++)
   {
      printf("y[%d]=",i);
      scanf("%f",&y[i]);                  
   }
  h=x[2]-x[1];
  printf("Enter the value of f:");
  scanf("%f%f",&low , &high);
  xn = (low + high)/2;
s=(xn-x[1])/h;
p=1;
d=y[1];                                  
for(i=1;i<=(n-1);i++)
 {
  for(j=1;j<=(n-i);j++)
   {
      y[j]=y[j+1]-y[j];
                             
    }
    p=p*(s-i+1)/i;
    d=d+p*y[1];
                   
 }                         
printf("For the value of x=%6.5f THe value is %6.5f",xn,d);
 return 0;
}
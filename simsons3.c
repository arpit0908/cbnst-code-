#include<stdio.h>    
#include<math.h>  
float f(float x)
{
    return 1/(1+pow(x,2));
}  
int main()  
{  
 float a, b, intgrl=0.0001, stepSize, k;  
 int i, h;  
  
 printf("Enter lower limit : ");  
 scanf("%f", &a);  
 printf("Enter upper limit: ");  
 scanf("%f", &b);  
 printf("Enter sub intervals: ");  
 scanf("%d", &h);  
stepSize = (b - a)/h;  
intgrl = f(a) + f(b);  
 for(i=1; i<= h-1; i++)  
 {  
  k = a + i*stepSize;  
  if(i%3 == 0)  
  {  
   intgrl = intgrl + 2 * f(k);  
  }  
  else  
  {  
   intgrl= intgrl + 3 * f(k);  
  }  
 }  
 intgrl = intgrl * stepSize*3/8;  
 printf("The integration is: %.3f", intgrl);  
  
 return 0;  
}  
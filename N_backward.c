#include<stdio.h>
#include<math.h>
 int main()
{
      float x[20],y[20],xn,s,d,h,p;
      int j,i,k,n;
      printf("enter the number of n :\n");
      scanf("%d",&n);
      printf("enter the element of x: \n");
      for(i=1;i<=n;i++)
      {
        printf("x[%d]=",i);
        scanf("%f",&x[i]);
      }
      printf("enter the value of y: \n");
      for(i=1;i<=n;i++)
      {
        printf("y[%d]=",i);
        scanf("%f",&y[i]);
      }     
      h=x[2]-x[1];
      printf("enter the value of f:");                  
      scanf("%f",&xn);
      s=(xn-x[n])/h;
      d=y[n];
      p=1;
      for(i=n,k=1;i>=1,k<n;i--,k++)
      {
         for(j=n;j>=1;j--)
         {
            y[j]=y[j]-y[j-1];
         }
            p=p*(s+k-1)/k;
            d=d+p*y[n];
}
      printf("for f=%f ,ans is=%f",xn,d);
      return 0;
}
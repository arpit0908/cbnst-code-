#include<stdio.h>
#include<math.h>
float f(float x)
{
    return x*x ;
}
int  main()
{
    int i,n;
    float x0,xn,h,y[20],so,se,ans,x[20];
    printf("\n Enter values of x0: ");
    scanf("%f",&x0);
    printf("\n Enter values of xn: ");
    scanf("%f",&xn);
    printf("\n Enter values of h:  ");
    scanf("%f",&h);
    n=(xn-x0)/h;
    if(n%2==1)
    {
        n=n+1;
    }
    h=(xn-x0)/n;
    printf("\n refined value of n and h are:%d  %f\n",n,h);
    printf("\n Y values \n");
    for(i=0; i<=n; i++)
    {
        x[i]=x0+i*h;
        y[i]=f(x[i]);
        printf("\n%f\n",y[i]);
    }
    so=0;
    se=0;
    for(i=1; i<n; i++)
    {
        if(i%2==1)
        {
            so=so+y[i];
        }
        else
        {
            se=se+y[i];
        }
    }
    ans=h/3*(y[0]+y[n]+4*so+2*se);
    printf("\nfinal integration is %f",ans);
    return 0 ;
}
#include<stdio.h>
#include<math.h>
double f(double x, double y){
    return y-x/y+x;  
}
main(){
    int i;
    double y,xi,yi,xf,h;
    printf("Enter the initial value of y: ");
    scanf("%lf",&yi);
    printf("Enter the initial value of x: ");
    scanf("%lf",&xi);
    printf("Enter the value of x for which y is required: ");
    scanf("%lf",&xf);
    printf("Enter the value of  h: ");
    scanf("%lf",&h);
    printf("x\t\ty\t\ty'\t\thy'\t\ty+hy'\n");
    printf("__________________________________________________________________________\n");
    while(xi<xf){
        y=yi+h*f(xi,yi);
        printf("%lf\t%lf\t%lf\t%lf\t%lf\n",xi,yi,f(xi,yi),h*f(xi,yi),y);
        yi=y;
        xi=xi+h;
    }
    printf("%lf\t%lf\n",xi,yi);
    printf("__________________________________________________________________________\n");
    printf("The value of y is %lf\n\n",y);
}
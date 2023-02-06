#include <stdio.h>
#include <math.h>

float FUN(float x, float y)
{
    return x*x/2*y;
}

void Euler_method()
{
    float y0, x0, y, x;
    int n;
    printf("Enter the initial value of y and x : ");
    scanf("%f%f", &y0, &x0);
    printf("Enter the x for which y is required : ");
    scanf("%f", &x);
    printf("Enter the number of iteration : ");
    scanf("%d", &n);
    float h = (float)(x - x0) / n;
    for (int i = 0; i < n; i++)
    {
        y = y0 + h * FUN(x0 + i * h, y0);
        y0 = y;
        printf("Iteration %d : y = %f\n", i + 1, y0);
    }
    printf("Value : %f\n", y);
}

void Runge_Kutta_method()
{
    float y0, x0, y, x, k1, k2, k3, k4, k;
    int n;
    printf("Enter the initial value of y and x : ");
    scanf("%f%f", &y0, &x0);
    printf("Enter the x for which y is required : ");
    scanf("%f", &x);
    printf("Enter the number of iteration : ");
    scanf("%d", &n);
    float h = (float)(x - x0) / n;
    for (int i = 0; i < n; i++)
    {
        k1 = h * FUN(x0, y0);
        k2 = h * FUN(x0 + h / 2.0, y0 + k1 / 2.0);
        k3 = h * FUN(x0 + h / 2.0, y0 + k2 / 2.0);
        k4 = h * FUN(x0 + h, y0 + k3);
        k = (k1 + k2 + k3 + k4) / 6.0;
        y = y0 + k;
        y0 = y;
        x0 = x0 + h;
         printf("Iteration %d : y = %f\n", i + 1, y0);
    }
    printf("Value : %f\n", y);
}
    int main()
{
    int choice;
   printf("enter the valuefor\n1 for euler method and \n2 for runga kutta ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        Euler_method();
        break;
    case 2:
        Runge_Kutta_method();
        break;
    default:
        printf("Invalid Choice \n");
    }

     return 0;
}

#include <stdio.h>
#include <math.h>

void newton_forword()
{
    float x[20], y[20], xn, s, h, d, p; // n- total no of values ,s = n in the formula y find = d,
    int j, i, n;
    printf("enter the value of n :\n");
    scanf("%d", &n);
    printf("enter the elements of x:\n");
    for (i = 1; i <= n; i++)
    {
        printf("x[%d]=", i);
        scanf("%f", &x[i]);
    }
    printf("enter the elements of y:\n");
    for (i = 1; i <= n; i++)
    {
        printf("y[%d]=", i);
        scanf("%f", &y[i]);
    }
    h = x[2] - x[1];
    printf("Enter the value of f:");
    scanf("%f", &xn);
    s = (xn - x[1]) / h;
    p = 1;
    d = y[1];
    for (i = 1; i <= (n - 1); i++)
    {
        for (j = 1; j <= (n - i); j++)
        {
            y[j] = y[j + 1] - y[j];
        }
        p = p * (s - i + 1) / i;
        d = d + p * y[1];
    }
    printf("For the value of x=%6.5f The value is %6.5f", xn, d);
}

void newton_backward()
{
    float x[20], y[20], xn, s, d, h, p;
    int j, i, k, n;
    printf("enter the number of n :\n");
    scanf("%d", &n);
    printf("enter the element of x: \n");
    for (i = 1; i <= n; i++)
    {
        printf("x[%d]=", i);
        scanf("%f", &x[i]);
    }
    printf("enter the value of y: \n");
    for (i = 1; i <= n; i++)
    {
        printf("y[%d]=", i);
        scanf("%f", &y[i]);
    }
    h = x[2] - x[1];
    printf("enter the value of f:");
    scanf("%f", &xn);
    s = (xn - x[n]) / h;
    d = y[n];
    p = 1;
    for (i = n, k = 1; i >= 1, k < n; i--, k++)
    {
        for (j = n; j >= 1; j--)
        {
            y[j] = y[j] - y[j - 1];
        }
        p = p * (s + k - 1) / k;
        d = d + p * y[n];
    }
    printf("for f=%f ,ans is=%f", xn, d);
}

int main()
{
    int choice;
    printf("Enter the choice \n1 for newton forward\n2 for newton backward\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        newton_forword();
        break;
    case 2:
        newton_backward();
        break;
    default:
        printf("Invalid choice \n");
    }

    return 0;
}
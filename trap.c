#include<stdio.h>
#include<stdlib.h>
#include<math.h>


float fun(float x)
{
    return x*x ;
}

void Simpson_1_by_3_Rule()
{
    float a, b ; 
    int n, k = 1;
    printf("Enter the value of a and b : ");
    scanf("%f%f", &a, &b);
    printf("Enter the number of interval : ");
    scanf("%d", &n);
    float h = (float)(b - a) / n, sum = 0;
    sum += (fun(a) + fun(b));
    for (float i = a + h; i < b; i = i + h)
    {
        if (k++ % 2 == 0)
            sum += 2 * fun(i);
        else
            sum += 4 * fun(i);
    }
    sum = sum * h / 3.0;
    printf("Valus of integral : %f", sum);
}

void Simpson_3_by_8_Rule()
{
    float a, b ;
    int n, k = 1 ;
    printf("Enter the value of a and b : ");
    scanf("%f%f", &a, &b) ;
    printf("Enter the number of interval : ");
    scanf("%d", &n);
    float h = (float)(b - a) / n, sum = 0;
    sum += (fun(a) + fun(b));
    for (float i = a + h; i < b; i = i + h)
    {
        if (k++ % 3 == 0)
            sum += 2 * fun(i);
        else
            sum += 3 * fun(i);
    }
    sum = sum * (3 * h) / 8.0;
    printf("Valus of integral : %f", sum);
}

void Trapezoidal_Rule()
{
    float a, b;
    int n;
    printf("Enter the value of a and b : ");
    scanf("%f%f", &a, &b);
    printf("Enter the number of interval : ");
    scanf("%d", &n);
    float h = (float)(b - a) / n, sum = 0;
    sum += (fun(a) + fun(b)) /2 ;
    for (float i = a + h; i < b; i = i + h)
    {
        sum += fun(i);
    }
    sum = sum * h ;
    printf("Valus of integral : %f", sum);
}
int main()
{
    int choice;
    printf("enter the choice\n1 for simson_1_by_3 rule\n2 for simson_3_by_8 rule\n3 for trapezoidal rule :");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        Simpson_1_by_3_Rule();
        break;
    case 2:
        Simpson_3_by_8_Rule();
        break;
    case 3:
        Trapezoidal_Rule();
        break;
    default:
        printf("Invalid choice \n");
    }

    return 0;
}
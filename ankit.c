#include <stdio.h>
#include <math.h>

void gauss_elimination()
{
    int n;
    printf("Enter the order of the matrix : ");
    scanf("%d", &n);
    float m[n][n + 1], sol[n], sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++)
            scanf("%f", &m[i][j]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j > i)
            {
                float ratio = m[j][i] / m[i][i];
                for (int k = 0; k <= n; k++)
                    m[j][k] = m[j][k] - ratio * m[i][k];
            }
        }
    }

    sol[n - 1] = m[n - 1][n] / m[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)

            sum += m[i][j] * sol[j];
        sol[i] = (m[i][n] - sum) / m[i][i];
        sum = 0;
    }
    printf("Solution : ");
    for (int i = 0; i < n; i++)
        printf("%f\t", sol[i]);
}

void gauss_jordon()
{
    int n;
    printf("Enter the order of the matrix : ");
    scanf("%d", &n);
    float m[n][n + 1], sol[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++)
            scanf("%f", &m[i][j]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                float ratio = m[j][i] / m[i][i];
                for (int k = 0; k <= n; k++)
                    m[j][k] = m[j][k] - ratio * m[i][k];
            }
        }
    }
    for (int i = 0; i < n; i++)
        sol[i] = m[i][n] / m[i][i];

    printf("Solution : ");
    for (int i = 0; i < n; i++)
        printf("%f\t", sol[i]);
}

void gauss_seidel(int N)
{
    int n, flag = 0;
    printf("Enter the order of the matrix : ");
    scanf("%d", &n);
    float m[n][n + 1], sol[n], sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++)
            scanf("%f", &m[i][j]);
    float new_val[n], old_val[n];
    for (int i = 0; i < n; i++)
    {
        new_val[i] = 0;
        old_val[i] = 0;
    }
    for (int itr = 0; itr < N; itr++)
    {
        for (int i = 0; i < n; i++)
        {
            sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                    sum += m[i][j] * new_val[j];
            }
            new_val[i] = (m[i][n] - sum) / m[i][i];
        }
        for (int i = 0; i < n; i++)
        {
            if (fabs(new_val[i] - old_val[i]) < 0.001)
                continue;
            else
                flag = 1;
        }
        if (flag == 0)
        {
            printf("Solution : ");
            for (int i = 0; i < n; i++)
                printf("%f\t", new_val[i]);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            old_val[i] = new_val[i];
            printf(" X%d : %f\t", i + 1, new_val[i]);
        }
        flag = 0;
        printf("\n");
    }
}

float fun(float x)
{
    return  pow(x, 2);
}

void Simpson_1_by_3_Rule()
{
    float a, b;
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
    float a, b;
    int n, k = 1;
    printf("Enter the value of a and b : ");
    scanf("%f%f", &a, &b);
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
    sum += (fun(a) + fun(b)) / 2.0;
    for (float i = a + h; i < b; i = i + h)
    {
        sum += fun(i);
    }
    sum = sum * h;
    printf("Valus of integral : %f", sum);
}


void Straight_Line_Curve_Fitting()
{
    int n;
    printf("Enter the number of points : ");
    scanf("%d", &n);
    float x[n], y[n], a = 0, b = 0;
    printf("Enter the y and x \n");
    for (int i = 0; i < n; i++)
        scanf("%f%f", &y[i], &x[i]);
    float sum_x = 0, sum_y = 0, sum_xy = 0, sum_xx = 0;
    for (int i = 0; i < n; i++)
    {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_xx += x[i] * x[i];
    }
    // printf("%.2f\t=\t%d*a\t+\t%.2f*b\n", sum_y, n, sum_x);
    // printf("%.2f\t=\t%.2f*a\t+\t%.2f*b\n", sum_xy, sum_x, sum_xx);
    b = ((n * sum_xy - sum_x * sum_y) * 1.0 / (n * sum_xx - sum_x * sum_x) * 1.0);
    a = (float)(sum_y - b * sum_x) / n;
    printf("\n\nThe line is Y\t=\t%3.3f\t+\t%3.3f*X", a, b);
}

void Parabola_Curve_Fitting()
{
    int n;
    printf("Enter the number of points : ");
    scanf("%d", &n);
    float x[n], y[n];
    printf("Enter the y and x \n");
    for (int i = 0; i < n; i++)
        scanf("%f%f", &y[i], &x[i]);
    float sum_x = 0, sum_y = 0, sum_xy = 0, sum_yx2 = 0, sum_x2 = 0, sum_x3 = 0, sum_x4 = 0;
    for (int i = 0; i < n; i++)
    {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_yx2 += y[i] * x[i] * x[i];
        sum_x2 += x[i] * x[i];
        sum_x3 += x[i] * x[i] * x[i];
        sum_x4 += x[i] * x[i] * x[i] * x[i];
    }
    float m[3][4];
    m[0][0] = sum_x2;
    m[0][1] = sum_x;
    m[0][2] = n;
    m[0][3] = sum_y;
    m[1][0] = sum_x3;
    m[1][1] = sum_x2;
    m[1][2] = sum_x;
    m[1][3] = sum_xy;
    m[2][0] = sum_x4;
    m[2][1] = sum_x3;
    m[2][2] = sum_x2;
    m[2][3] = sum_yx2;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j != i)
            {
                float r = m[j][i] / m[i][i];
                for (int k = 0; k <= 3; k++)
                    m[j][k] = m[j][k] - r * m[i][k];
            }
        }
    }
    float sol[3];
    for (int i = 0; i < 3; i++)
        sol[i] = m[i][3] / m[i][i];

    printf("\n\nThe line is Y\t=\t%3.3f*X^2 + %3.3f*X + %3.3f", sol[0], sol[1], sol[2]);
}

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
    printf("Enter the choice \n1 for Gauss Elimination\n2 for Gauss Jordon\n3 for Gauss Seidel\n4 for Trapezoidal_Rule\n5 for Simpson_1_by_3_Rule\n");
    printf("6 for Simpson_3_by_8_Rule\n7 for Straight_Line_Curve_Fitting\n8 for Parabola_Curve_Fitting\n9 for eulers method \n10 for runge kutta method \n");

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        gauss_elimination();
        break;
    case 2:
        gauss_jordon();
        break;
    case 3:
        gauss_seidel(10);
        break;
    case 4:
        Trapezoidal_Rule();
        break;
    case 5:
        Simpson_1_by_3_Rule();
        break;
    case 6:
        Simpson_3_by_8_Rule();
        break;
    case 7:
        Straight_Line_Curve_Fitting();
        break;
    case 8:
        Parabola_Curve_Fitting();
        break;
    case 9:
        Euler_method();
        break;
    case 10:
        Runge_Kutta_method();
        break;
    default:
        printf("Invalid Choice \n");
    }

     return 0;
}
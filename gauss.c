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

int main()
{
    int choice;
    printf("Enter the choice \n1 for Gauss Elimination\n2 for Gauss Jordon\n3 for Gauss Seidel\n");

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

    default:
        printf("Invalid Choice \n");
    }

    return 0;
}
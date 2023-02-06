#include<stdio.h>
int main()
{
    int n;
    printf("enter the value of the n :");
    scanf("%d" , &n);
   
    
    float M[n][n+1];
    for(int i=0; i<n ; i++)
    {
        for(int j=0  ; j<n+1 ; j++)
        scanf("%f", &M[i][j]);
        
    }
    for(int i=0 ; i<n ; i++)
    {
        for(int j = 0 ; j< n ; j++)
        {
            if(i!=j)
            {
                float ratio= M[j][i]/M[i][i];
                for(int k = 0 ;k<n+1 ; k++)
                {
                    M[j][k]= M[j][k] - ratio*M[i][k];
                    
                }
            }
        }
    }
    
    printf("Value of x:  %f\n" , M[0][n]/M[0][0]);
     printf("Value of y:  %f\n" , M[1][n]/M[1][1]);
      printf("Value of z:  %f\n" , M[2][n]/M[2][2]);
     return 0;
    
    
    
}


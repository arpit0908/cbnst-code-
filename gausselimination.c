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
            if(i<j)
            {
                float ratio= M[j][i]/M[i][i];
                for(int k = 0 ;k<n+1 ; k++)
                {
                    M[j][k]= M[j][k] - ratio*M[i][k];
                    
                }
            }
        }
    }
    
    
    float x , y ,z ;
     z = M[2][3]/M[2][2];
     y = (M[1][3] - z*M[1][2])/M[1][1];
     x = (M[0][3] - y*M[0][1] - z*M[0][2])/M[0][0];
     
    printf("Value of x:  %f\n" ,x );
     printf("Value of y:  %f\n" , y  );
      printf("Value of z:  %f\n" , z);
      
      return 0 ;
}
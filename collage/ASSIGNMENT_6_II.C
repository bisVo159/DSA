#include<stdio.h>
int main(){
    /*int n,m;
    printf("Enter number of rows\n");
    scanf("%d",&n);
    printf("Enter number of columns\n");
    scanf("%d",&m);
    int a[n][m];
    printf("Enter value for 2D matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("The matrix is\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }*/

    /*int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
     for(int i=0;i<3;i++){
         for(int j=i;j<3;j++){
              int temp=a[i][j];
              a[i][j]=a[j][i];
              a[j][i]=temp;
         }
     }
     printf("The tranpose of the given matrix is\n");
      for(int i=0;i<3;i++){
         for(int j=0;j<3;j++){
             printf("%d ",a[i][j]);
         }printf("\n");
      }*/

     /* int r,c,a[100][100],b[100][100],sum[100][100];
      printf("Enter the number of rows and columns\n");
      scanf("%d%d",&r,&c);
      printf("Enter elements for the first matrix:\n");
      for(int i=0;i<r;i++){
          for(int j=0;j<c;j++){
              scanf("%d",&a[i][j]);
          }
      }
      printf("Enter elements for the second matrix:\n");
      for(int i=0;i<r;i++){
          for(int j=0;j<c;j++){
              scanf("%d",&b[i][j]);
          }
      }
      for(int i=0;i<r;i++){
          for(int j=0;j<c;j++){
              sum[i][j]=a[i][j]+b[i][j];
          }
      }
      printf("Sum of two matrix:\n");
      for(int i=0;i<r;i++){
          for(int j=0;j<c;j++){
              printf("%d ",sum[i][j]);
          }printf("\n");
      }*/

      int n1,n2,n3;
      scanf("%d%d%d",&n1,&n2,&n3);
      int m1[n1][n2],m2[n2][n3],mul[n1][n3];
      printf("Enter 1st matrix elements:\n");
        for(int i=0;i<n1;i++){
          for(int j=0;j<n2;j++){
              scanf("%d",&m1[i][j]);
          }
      }
      printf("Enter 2nd matrix elements:\n");
        for(int i=0;i<n2;i++){
          for(int j=0;j<n3;j++){
              scanf("%d",&m2[i][j]);
          }
      }
        for(int i=0;i<n1;i++){
          for(int j=0;j<n3;j++){
              mul[i][j]=0;
          }
      }
           for(int i=0;i<n1;i++){
         for(int j=0;j<n3;j++){
             for(int k=0;k<n2;k++){
                 mul[i][j]+=m1[i][k]*m2[k][j];
             }
         }
} 
for(int i=0;i<n1;i++){
    for(int j=0;j<n3;j++){
        printf("%d  ",mul[i][j]);
    }
    printf("\n");
}
}
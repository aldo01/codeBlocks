#include<stdio.h>
#define R 3
#define C 3

int transpose(int [R][C]);
int swap(int * , int *);
int printMatrix(int [R][C], int , int);
int main()
{
    int a[R][C] = { {1,  2,  3},
        {7,  8,  9},
        {13, 14, 15}
    };

    transpose(a);
    printMatrix(a,R,C);
    return 0;
}

 int transpose(int arr[R][C]){
    for(int i=0;i<R;i++)
    for(int j=0;j<C;j++)
        swap(&arr[i][j],&arr[j][i]);
 }

 int swap(int *x, int *y){
  int *temp;
  *temp=*x;
  *x=*y;
  *y=*temp;
 }

int printMatrix(int arr[R][C], int m, int n){
   for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
     printf(" %d ",arr[i][j]);
}

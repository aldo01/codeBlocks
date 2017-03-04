#include<stdio.h>
#define M 4
#define N 4

int printSpiral(int [M][N], int, int);

int main(){
 int arr[M][N]={
              {2,4,6,8},
              {5,9,12,16},
              {2,11,5,9},
              {3,2,1,8}
          };

    printSpiral(arr,M,N);

    return 0;
}

int printSpiral(int arr[M][N],  int m,  int n){
   int t=0;
   int b=m-1;
   int l=0;
   int r=n-1;
   int dir=0;
   while(t<=b && l<=r){
    if(dir==0){
        for(int i=l;i<=r;i++ )
            printf(" %d ",arr[t][i]);

          t++;
    }

    else if(dir==1){
        for(int i=t; t<=b; i++)
            printf(" %d ",arr[i][r]);

        r--;
    }

    else if(dir==2){

        for(int i=r ;i>=l ;i--)
            printf(" %d ", arr[b][i]);

        b--;
    }

    else if(dir==3){
        for(int i=b; i>=t;i--)
            printf(" %d ", arr[i][l]);

        l++;

    }
    dir=(dir+1)%4;
   }
}

#include<stdio.h>

#define N 3
#define M 4

int countNegative(int [][M], int, int);
int main(){

    int arr[N][M]={
              {-3,-2,-1,1},
              {-2,2,3,4},
              {4,5,7,8},
    };

    printf("%d ", countNegative(arr,N,M));

}


int countNegative(int arr[N][M], int n, int m){

 int i=0;
 int j=m-1;
 int count=0;

 while(j>=0 && i<=n){
    if(arr[i][j]<0){
        count=count+(j+1);
        i++;
    }
    else
        j--;

 }
}

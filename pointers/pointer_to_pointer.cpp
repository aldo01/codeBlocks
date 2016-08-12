#include<stdio.h>

 int disp(int *);
 int show(int **);

  int main(){
   int i;
   //int **k;
   int arr[]={10,45,33,22,6,7};
    for(i=0;i<=5;i++){
      disp(&arr[i]);
     // return 0;
    }
  }
   int disp(int *n){

    show(&n);
    }
     int show(int **k){
      // int **k;
      printf(" %d \n",**k);
     }

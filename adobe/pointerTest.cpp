#include<stdio.h>

int main(){
 int arr[]={1,2,3,4,5,6,7,8,9};
 int j=0;
 int num=5;
 num=8;
 printf("%d\n",sizeof(arr));
 for(j=0;j<9;j++){
    printf("%d",*arr);
    (*arr)++;
 }
 return 0;
}

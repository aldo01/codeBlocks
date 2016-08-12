#include<stdio.h>
#include<stdlib.h>

int bubble(int [],int);
int swap(int *,int *);
int printArray(int [],int);
 int main(void){
   int arr[]={55,2,6,12,3,1};
   int n=sizeof(arr)/sizeof(arr[0]);
   bubble(arr,n);
   printArray(arr,n);
   return 0;

 }

 int bubble(int arr[],int size){
  int i,j;
   for(i=0;i<size;i++)
   for(j=0;j<size-1;j++)
    if(arr[j]<arr[j+1]){  // decreasing order sort
     swap(&arr[j],&arr[j+1]);
    }
 }
 int swap(int *x,int *y){
  int temp;
  temp=*x;
  *x=*y;
  *y=temp;
 }

int printArray(int arr[], int size){
  int i;
 for(i=0;i<size;i++)
  printf(" %d",arr[i]);
}

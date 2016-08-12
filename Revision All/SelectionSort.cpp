#include<stdio.h>
#include<stdlib.h>

 int selectionSort(int arr[], int );
 int printArray(int [],int);
 int swap(int *,int *);

 int main(){
  int arr[]={55,2,6,12,3,1};
  int n=sizeof(arr)/sizeof(arr[0]);
  selectionSort(arr,n);
  printArray(arr,n);
  return 0;
 }

int selectionSort(int arr[],int n){
int i,j;
  for(i=0;i<n-1;i++){
    int min_idx=i;
    for(j=i+1;j<n;j++)
     if(arr[j]<arr[min_idx])
      min_idx=j;
       swap(&arr[min_idx],&arr[i]);


  }
}
int swap(int *x,int *y){
 int temp=*x;
 *x=*y;
 *y=temp;
}
int printArray(int arr[],int size){
 int i;
 for(i=0;i<size;i++){
  printf(" %d ",arr[i]);

 }
}

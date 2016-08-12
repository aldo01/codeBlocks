#include<stdio.h>
#include<stdlib.h>


int shellSort(int [],int);
int printArray(int [],int);

 int main(void){
  int arr[]={3,4,1,2,7};
  int n=sizeof(arr)/sizeof(arr[0]);
  shellSort(arr,n);
  printArray(arr,n);
  return 0;
 }

  int shellSort(int arr[], int n){
   int i,temp;
   int gap;
   for(gap=n/2 ; gap>0 ; gap/=2){

    for(i=gap;i<n;i++){
     temp=arr[i];
      int j;
     for( j =i-1 ; j>=gap && arr[j-gap]>temp ; j-=gap)
       arr[j]=arr[j-gap];

       arr[j]=temp;

    }
   }
   return 0;
  }

 int printArray(int arr[],int n){
  for(int i=0;i<n;i++)
  printf("%d ",arr[i]);

 }

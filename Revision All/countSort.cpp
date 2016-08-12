#include<stdio.h>
#include<stdlib.h>

 int countSort(int arr[],int n,int len){
  int i,j,k;
  int count[n];
  for(i=0;i<len;i++)
   count[arr[i]]++;

   for(i=0;i<15;i++){
     while(count[i]>0){
      printf("%d ",i);
     }

   }

   // printf(" %d ",count[i]);

 }

 int main(){
  int arr[]={1,9,6,10,4,2,3,6,7,1,2,9};
  int size=sizeof(arr)/sizeof(arr[0]);
  countSort(arr,15,12);
  return 0;
 }

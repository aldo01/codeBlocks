#include<stdio.h>
#include<stdlib.h>

  int printArray(int [],int );
  int rotation(int [],int,int);

int main(){
 int arr[]={1,2,4,5};
 int n=sizeof(arr)/sizeof(arr[0]);
 printArray(arr,n);
 rotation(arr,0,n-1);
 printArray(arr,n);
 return 0;
}

int rotation(int arr[],int l,int e){
int temp=0;
 while(l<e){
  temp=arr[l];
  arr[l]=arr[e];
  arr[e]=temp;
  l++;
  e--;
 }
}
int printArray(int arr[],int n){
 int i;
 for(i=0;i<n;i++)
 printf(" %d ",arr[i]);
}

#include<stdio.h>
#include<malloc.h>
#define MAX 20
 int BinarySearch(int [],int ,int,int);
 int main(void){
  int arr[]={2,5,10,34,45,90};
  int n= sizeof(arr)/sizeof(arr[0]);
  printf(" %d \n",n);
  int x=10;
  printf("index of 10 is %d",BinarySearch(arr,0,n-1,x));
  return 0;
 }
 int BinarySearch(int arr[],int l,int r,int x){
  if(r>=l){
   int mid=(l+r)/2;
   if(arr[mid]==x)
    return mid;

   if(arr[mid]>x)
    return BinarySearch(arr,l,mid-1,x);

   if(arr[mid]<x)
    return BinarySearch(arr,mid+1,r,x);

  }
  return -1;
 }

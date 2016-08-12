#include<stdio.h>
#include<stdlib.h>


 int interpolation(int arr[],int low,int high,int x){

  //int high
  int toFind=x;

  while(high>low){

  int mid=low +((toFind-arr[low])*(high-low))/(arr[high]-arr[low]);

  if(arr[mid]==toFind)
   return mid;

  else if(arr[mid]>toFind)
    high=mid-1;

    else
     low=mid+1;
 }
  return 0;
 }

 int main(void){
  int arr[]={201,209,232,233,332,399,400};
  int n=sizeof(arr)/sizeof(arr[0]);
  int x=332;
  printf("index is %d",interpolation(arr,0,n-1,x));
  return 0;
 }

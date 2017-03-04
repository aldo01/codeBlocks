#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

 int kadane(int arr[], int n){
  int curr_max=arr[0];
  int total_max=arr[0];

  for(int i=1; i<n-1;i++){
     curr_max=max(arr[i],curr_max+arr[i]);
     total_max=max(curr_max,total_max);

  }
  return total_max;
 }

  int main(){
   int arr[]={-2, -3, 4, -1, -2, 1, 5, -3};
   int n=sizeof(arr)/sizeof(arr[0]);
   printf("%d ",kadane(arr,n));

   return 0;
  }

#include<stdio.h>
#include<stdlib.h>
//#include<hash_map>
#include<algorithm>
//#include<iostream>
using namespace std;

 bool triplets(int [],int);

int main(){
  int arr[]={1,3,2,5,4};
  int size= sizeof(arr)/sizeof(arr[0]);
 bool d= triplets(arr,size);
 printf("\n%d",d);
  return 0;
 }

 bool triplets(int arr[],int size){
 int i;
  for(i=0;i<size;i++)
   arr[i]=arr[i]*arr[i];

   sort(arr,arr+size);
   for(i=size-1 ;i>=2 ;i--){
     int l=0;
     int r=i-1;

     while(l<r){
      if(arr[l]+arr[r]==arr[i]){
      printf("%d %d %d",arr[i],arr[l],arr[r]);
       return true;
       }

       (arr[l] + arr[r] < arr[i])?  l++: r--;
     }
   }
    return false;
 }

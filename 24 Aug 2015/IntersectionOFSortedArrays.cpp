#include<stdio.h>
#include<stdlib.h>



 int Intersection(int [],int [],int ,int);
int main(){
 int arr1[]={1,2,5,7,8};
 int arr2[]={1,3,5,7,8};
 int size1=sizeof(arr1)/sizeof(arr1[0]);
   int size2=sizeof(arr2)/sizeof(arr2[0]);
   Intersection(arr1,arr2,size1,size2);
   return 0;

 }

 int Intersection(int arr1[],int arr2[],int m,int n){
  int i=0,j=0;
  while(i<m && j<n){
   if(arr1[i]==arr2[j]){
   printf(" %d ",arr1[i]);
   i++;
   j++;
   }
  else if(arr1[i]<arr2[j]){
     i++;
   }
   else
   j++;

  }
 }

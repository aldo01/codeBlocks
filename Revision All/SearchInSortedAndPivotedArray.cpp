/**
    median of two sorted arrays.
**/


#include<stdio.h>
#define MAX 50

int mergeArray(int [],int []);
 int main(){
  int arr1[]={2,3,7,9};
  int arr2[]={1,4,5,8};
  int len1= sizeof(arr1)/sizeof(arr1[0]);

  mergeArray(arr1,arr2);
  return 0;

  }

  int mergeArray(int arr1[],int arr2[]){
   int c[MAX]={0};
   int i=0,j=0,k=0;
   int len1=sizeof(arr1)/sizeof(arr1[0]);
   int len2=sizeof(arr2)/sizeof(arr2[0]);

   while(i<len1 && j<len2){
    if(arr1[i]<=arr2[j]){
      c[k]=arr1[i];
      k++;
      i++;
    }
    else{
     c[k]=arr2[j];
     k++;
     j++;
    }
   }
   while(i<len1){
    c[k]=arr1[i];
    k++;i++;
   }

   while(j<len2){
    c[k]=arr2[j];
    j++;k++;
   }
    for(i=0;i<9;i++)
     printf(" %d ",c[i]);
  }





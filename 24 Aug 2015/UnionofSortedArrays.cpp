#include<stdio.h>
#include<stdlib.h>


  int UnionSet(int arr1[],int arr2[],int m,int n){
   int i=0,j=0;
   while(i<m && j<n){
   if(arr1[i]<arr2[j])
    printf(" %d ", arr1[i++]);

    else if(arr1[i]>arr2[j])
      printf(" %d ",arr2[j++]);

      else{
      printf(" %d ",arr2[j++]);
      i++;
      }
   }
   while(i<m){printf(" %d ",arr1[i++]);}
   while(j<n){printf(" %d ",arr2[j++]);}
  }

  int main(){
   int arr1[]={1,4,6,9};
   int arr2[]={1,3,6,9,10};
   int size1=sizeof(arr1)/sizeof(arr1[0]);
   int size2=sizeof(arr2)/sizeof(arr2[0]);
   UnionSet(arr1,arr2,size1,size2);
   return 0;
  }

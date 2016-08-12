#include<stdio.h>
#include<stdlib.h>
#define MAX 30

 int merge(int arr[],int,int,int);
 int mergeSort(int arr[],int i,int j){
  int k;
  if(i<j){
  k=(i+j)/2;
   mergeSort(arr,i,k);
   mergeSort(arr,k+1,j);
   merge(arr,i,k,j);
  }
 }

 int merge(int arr[],int l,int m,int u){
  int c[MAX];
  int i,j,k;
  i=l;
  j=m+1;
  k=0;
  while(i<=m && j<=u){
   if(arr[i]<arr[j]){
    c[k]=arr[i];
    k++;i++;
   }
   else{
    c[k]=arr[j];
    k++;j++;
   }
  }
  while(i<=m){
   c[k]=arr[i];
   i++;k++;
  }
  while(j<=u){
   c[k]=arr[j];
   j++;k++;
  }
   for(i=l,j=0;i<=u;i++,j++)
   arr[i]=c[j];
 }
 int main(){
  int arr[MAX],n,i;
  printf("enter nos of elemnts");
  scanf("%d",&n);
  for(i=0;i<n;i++)
   scanf("%d",&arr[i]);
   mergeSort(arr,0,n-1);
   printf("\nsorted data\n");
   for(i=0;i<n;i++)
    printf(" %d ",arr[i]);
    return 0;
 }

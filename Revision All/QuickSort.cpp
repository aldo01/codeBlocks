#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int QuickSort(int [],int,int);
 int partition(int [],int ,int);

int main(){
 int arr[MAX];
 int n,i;
 printf("enter the nos of elements");
 scanf("%d",&n);
 for(i=0;i<n;i++)
  scanf("%d",&arr[i]);
  QuickSort(arr,0,n-1);
  for(i=0;i<n;i++)
   printf(" %d ",arr[i]);
   return 0;
}

int partition(int arr[], int l,int u){
 int v,i,j,temp;
 v=arr[l];
 i=l;
 j=u+1;
 do{
   do
    i++;
    while(arr[i]<v && i<=u);

    do
    j--;
    while(v<arr[j]);
    if(i<j){
     temp=arr[i];
     arr[i]=arr[j];
     arr[j]=temp;

    }

 }while(i<j);
 arr[l]=arr[j];
 arr[j]=v;
 return(j);
}

 int QuickSort(int arr[],int l,int u){
  int j;
  if(l<u){
   j=partition(arr,l,u);
   QuickSort(arr,l,j-1);
   //QuickSort(arr,j+1,u);
   l=j+1;// tail recursive quick sort

  }
 }

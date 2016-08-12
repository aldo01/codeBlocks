#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

int QuickSort(int [], int,int);
int swap(int* ,int*);
int partition(int [], int, int );

int main(){
  //int arr[100];
  int n,c=0;

  scanf("%d",&n);
  int num=n;
   while(num!=0){
    num=num/10;
    c++;
   }
   int k=c;
   int arr[k];


   for(int i=k-1;i>=0;i--){
     arr[i]=n%10;
     n=n/10;
   }
   int size=sizeof(arr)/sizeof(arr[0]);
   QuickSort(arr,0,size-1);
   swap(arr, arr+(size-1));

     return 0;
   }

 int QuickSort(int arr[], int l ,int u){
  if(l<u){
   int p=partition(arr,l,u);
   QuickSort(arr,l,p-1);
   QuickSort(arr,p-1,u);
  }
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

int swap(int *n, int *m){
 int temp;
 temp=*n;
 *n=*m;
 *m=temp;
}

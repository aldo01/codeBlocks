#include<stdio.h>
#include<stdlib.h>

 int deleteCell(int [],int ,int);

int main(){
 int arr[]={1,2,3,4,5,6};
 int num=3;
 int size=sizeof(arr)/sizeof(arr[0]);
  int n=deleteCell(arr,size,num);
   for(int i=0;i<n;i++)
    printf(" %d ",arr[i]);
  return 0;

}

 int deleteCell(int arr[],int n,int num){
  int i;
  for(i=0;i<n;i++){
   if(arr[i]==num)
    break;
  }
   if(i<n)
    {
     n=n-1;
     for(int j=i;j<n;j++)
      arr[j]=arr[j+1];
    }
    return n;
 }

#include<stdio.h>
#include<malloc.h>

#define MAX 256
int majority(int [],int);

 int main(){
  int arr[]={1,3,2,5,1,2,1,2,1};
  int len=sizeof(arr)/sizeof(arr[0]);
  printf("%d",len);
  printf("%d",majority(arr,len));
}

 int majority(int arr[],int len){
  int count[MAX]={0};
  int i,k;
  int j=0;
  for(i=0;i<MAX;i++)
   count[arr[i]]++;

   while(j<MAX){
    if(count[j]>(len/2))
     int k= count[j];
     else
     j++;
   }
   return k;
 }


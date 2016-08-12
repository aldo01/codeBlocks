/**
 Write a C program that, given an array A[] of n numbers and another number x,
  determines whether or not there exist two elements in S whose sum is exactly x.

  1) Initialize Binary Hash Map M[] = {0, 0, …}
  2) Do following for each element A[i] in A[]
      (a)	If M[x  - A[i]] is set then print the pair (A[i], x – A[i])
      (b)	Set M[A[i]]

      @author Nimish
**/

#include<stdio.h>
#include<stdlib.h>
#define MAX 100000

int findPair(int [],int ,int );
int main(){
 int arr[]={1,3,2,11,4,16,5,9,20};
 int sum=20;
 int size=sizeof(arr)/sizeof(arr[0]);
 findPair(arr,size,sum);
 return 0;
}

 int findPair(int arr[],int size,int sum){
  int i,temp;
  bool bitMap[MAX]={0};
  for(i=0;i<size;i++){
   temp=sum-arr[i];
    if(temp>=0 && bitMap[temp]==1){
    printf("the sum %d is made of %d %d\n",sum,temp,arr[i]);
   }
   bitMap[arr[i]]=1;
  }
  }

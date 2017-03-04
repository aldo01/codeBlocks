#include<stdio.h>
#include<malloc.h>

int countOne(int[], int , int);

int main(){
 int arr[]={1,1,0,0,0,0,0};
 int size=sizeof(arr)/sizeof(arr[0]);
 int count= countOne(arr,0,size-1);
 printf("%d",count);

 return 0;
}

int countOne(int arr[], int low, int high){
  if(low<=high){
    int mid=low+(high-low)/2;
    if((mid==high || arr[mid+1]==0) && (arr[mid]==1)){
        return mid+1;
    }
    if(arr[mid]==1)
        return countOne(arr,mid+1,high);

    else
    return countOne(arr,low,mid-1);
  }
  return 0;
}

#include<stdio.h>

  int reverseRotate(int[], int, int);
  int reverse(int[], int, int);
  int printArray(int [], int);
 int main(){
    int arr[]={1,2,3,4,5,6};
    reverseRotate(arr,sizeof(arr)/sizeof(arr[0]),2);

    printArray(arr,sizeof(arr)/sizeof(arr[0]));

    return 0;
}

 int reverseRotate(int arr[], int n, int k){
  reverse(arr,0,k-1);
  reverse(arr, k,n-1);
  reverse(arr,0,n-1);
}
int reverse(int arr[], int start, int end){
  while(start<end){
    int temp=arr[start];
    arr[start]=arr[end];
    arr[end]=temp;
    start++;
    end--;

  }
}

int printArray(int arr[], int n){
 for(int i=0; i<n;i++)
    printf(" %d ",arr[i]);
}

#include<stdio.h>

int leftRotate(int [], int, int);
int printArray(int [], int);
int reverseArray(int [], int, int);

int main(){
    int k=2;
 int arr[]={1,2,3,4,5,6};
 int n= sizeof(arr)/sizeof(arr[0]);


  leftRotate(arr,k,n);

  printArray(arr,n);

  return 0;


}

 int leftRotate(int arr[], int d, int n){
  reverseArray(arr,0,d-1);
  reverseArray(arr,d,n-1);
  reverseArray(arr, 0,n-1);
 }

 int reverseArray(int arr[], int start, int end){
  while(start<end){
    int temp=arr[start];
    arr[start]=arr[end];
    arr[end]=temp;
    start++;
    end--;

  }
 }

  int printArray(int arr[], int n){
    int i=0;
    for(i=0;i<n;i++)
        printf("%d ", arr[i]);
   }

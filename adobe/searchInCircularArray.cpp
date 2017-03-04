#include<stdio.h>

int pivotedBinarySearch(int [], int , int);
int binary_search(int[], int , int,  int);

int binary_search(int arr[], int l, int u, int key){
 int mid=l+(u-l)/2;

 if(l<u){
    if(arr[mid]==key)
        return mid;

    if(arr[mid]>key)
        return binary_search(arr,l,mid-1,key);

    if(arr[mid]<key)
       return binary_search(arr,mid+1,u,key);

 }
}

int main(){
  int arr1[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
   int n = sizeof(arr1)/sizeof(arr1[0]);
   int key = 3;
   printf("Index: %d\n", pivotedBinarySearch(arr1, n, key));
   return 0;
}

int pivotedBinarySearch(int arr[],int n, int key){
    int high=n; int low=0;
    int nos;
    int pivot=(low+high)/2;
       if(arr[0]>key  )
      nos=binary_search(arr,pivot+1,high, key);

   else
     nos=binary_search(arr,low,pivot-1, key);


   return nos;
}

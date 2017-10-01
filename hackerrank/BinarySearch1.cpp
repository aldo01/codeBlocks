#include<stdio.h>

int main(){
 int n=64;
 int arr[]={2,4,56,64,67,68,122,322,400,645};
 int size= sizeof(arr)/sizeof(arr[0]);
 printf("%d ",binarySearch(a,0,size,n));

 return 0;

}

int binarySearch(int arr[], int l, int u, int x){
int s=l;
int e=u;
  int mid=(l+u)/2;
  if(arr[mid]==x)
    return mid;

    if(arr[mid]>x)
       return binarySearch(arr,s,mid-1,x);

    else
       mid=mid+1;
       e=s;
}

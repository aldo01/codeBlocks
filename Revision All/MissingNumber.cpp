#include<stdio.h>
#include<stdlib.h>
 int FindMissing(int [],int);
 int main(){
 int arr[]={1,2,4,5,6};
 printf("%d",FindMissing(arr,5));
}
int FindMissing(int arr[],int size){
 int i;
 int n= size;
 int x1=arr[0];
 int x2=1;
 for(i=1;i<n;i++)
   x1=x1^arr[i];

   for(i=2;i<=n+1;i++)
    x2= x2^i;

    return (x1^x2);

}

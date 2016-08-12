#include<stdio.h>
#include<malloc.h>
#define MAX 1000

int findpairs(int [],int,int);

int main(){
 int arr[]={1,3,4,2,7,5,11,9,16};
 int n=sizeof(arr)/sizeof(arr[0]);
 int sum=20;
 //printf("%d",sizeof(arr[0]));

 findpairs(arr,n,sum);
 return 0;
}

int findpairs(int arr[],int size,int sum){
 bool bitmap[MAX]={0};
 int temp;
 for(int i=0;i<size;i++){
    temp=sum-arr[i];
    if(temp>=0 && bitmap[temp]==1)
    printf("%d %d are nos\n", temp,arr[i]);

    bitmap[arr[i]]=1;
 }
}

#include<stdio.h>
#include<ctype.h>
#include<math.h>
#define MAX 100


 int printList(int [], int);
 int printFact(int);
int main(){
 int n=36;
 printFact(n);
  return 0;
}

int printFact(int n){
 int arr[n/2];
  arr[0]=1;
  //arr[10]=n;
 for(int i=2;i<=sqrt(n);i++){
    if(n%i==0)
        arr[i]=i;
    if(i!=sqrt(n))
        arr[i+1]=n/i;


 }
 printList(arr,n);
}

int printList(int arr[], int n){
 for(int i=0; i<n/2;i++)
    printf(" %d ", arr[i]);
}

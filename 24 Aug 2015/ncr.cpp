#include<stdio.h>
#include<malloc.h>

int main(){
 int t;

 scanf("%d",&t);
 int arr[t];
 while(t--){
 int i=0;
 for(i=0;i<t;i++){
   scanf("%d",&arr[i]);
 }
 for(i=0;i<t;i++){
  if(arr[i]==0 || arr[i]==1 || arr[i]==2)
     return 0;
 }
  else if(arr[i]=3){
   return 6;
  }
  else if(arr[i]>3){
   int a=arr[i]-3;
    return factorial(arr[i])/(factorial(a) * factorial(a))
  }
 }
}

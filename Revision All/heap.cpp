#include<stdio.h>
#include<stdlib.h>
#define MAX 20

int create(int []);
int downAdjust(int [],int );

 int main(void){
   int heap[MAX];
   int n,i;
  // heap[0]=0;
   printf("enter the nos of elements");
   scanf("%d",&n);
   for(i=1;i<=n;i++)
    scanf("%d",&heap[i]);
    heap[0]=n;
   create(heap);
   // sorting using heap

   while(heap[0]>1){
    int last=heap[0];
    int temp=heap[1];
    heap[1]=heap[last];
    heap[last]=temp;
    heap[0]--;
    downAdjust(heap,1);
   }

   for(i=1;i<=n;i++)
    printf("%d",heap[i]);
    return 0;


  }

 int downAdjust(int heap[],int i){
  int j,temp;
  int n=heap[0];
  int flag=1;
  while(2*i<=n && flag==1){
   j=2*i;
   if(j+1<=n && heap[j+1]>heap[j])
    j=j+1;

    if(heap[i]>heap[j])
     flag=0;
     else{
       temp=heap[i];
       heap[i]=heap[j];
       heap[j]=temp;
       i=j;
     }

  }
 }

  int create(int heap[]){
   int n,i;
   n=heap[0];
   for(i=n/2;i>=1;i--)
     downAdjust(heap,i);
  }


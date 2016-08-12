#include<stdio.h>
//#include<conio.h>

 int insertNos(int arr[],int j,int n,int x);
 int n,j,x,i;
 int main(){
 int arr[50];

 printf("enter the nos of elements to be in the array\n");
  scanf("%d",&n);
  printf("enter the elements\n");
  for(int i=0;i<n;i++){
    scanf(" %d", &arr[i]);

   }
   for(i=0;i<n;i++){
   printf(" %d",arr[i]);
   }
   printf("enter the value of nos to be inserted");
   scanf("%d\n",&x);
   printf("enter the position of nos to inserted :");
   scanf("%d",&j);
   insertNos( arr,j,n,x);



 }
int insertNos(int *arr,int j,int n,int x){

   for(i=n-1;i>j-1;i--){
   arr[i+1]=arr[i];

   }
   n++;
   arr[j-1]=x;
  for(i=0;i<n;i++){
  printf("%d",arr[i]);
  }


}






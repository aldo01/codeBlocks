#include<stdio.h>
int InsertionSort(int, int);

int InsertionSort(int arr[],int n){
 int i,j,temp;
 for(i=1;i<=n;i++){
   temp=arr[i];
   for(j=i-1;j>=0 && arr[j]>temp;j--)
    arr[j+1]=arr[j];
    arr[j+1]=temp;
 }

}

int main(void){
  int arr[10],n;
  printf("enter the nos of elemnts");
  scanf("%d",&n);
  for(int i=0;i<=n;i++)
   scanf("%d",&arr[i]);
   InsertionSort(arr,n);
   for(int i=0;i<=n;i++)
    printf(" %d ",arr[i]);
    return 0;
}

/*find the element that appears only once
  take XOR of each element
*/

#include<stdio.h>
#include<stdlib.h>
int findElement(int [],int);

 int main(){
  int arr[]={2,3,2,4,5,4,6,6};
  int arr_size=sizeof(arr)/sizeof(arr[0]);
  //findElement(arr,arr_size);
  printf("%d",findElement(arr,arr_size));
 }
 int findElement(int arr[],int size){
  int i;
  int res=arr[0];
  for(i=1;i<size;i++){
   res=res^arr[i];
  }
  return res;
 }

#include<stdio.h>
#include<stdlib.h>



int binarySearch(int[], int, int,bool);
int main(){

 int arr[]={1,1,2,2,3,5,5,5,5,5,6,7,7,8};
 int firstSearch = binarySearch(arr,sizeof(arr)/sizeof(arr[0]),5,true);
 printf("%d",firstSearch);
   if(firstSearch==-1)
    printf(" %d ",0);
   else{
    int lastSearch=binarySearch(arr,sizeof(arr)/sizeof(arr[0]),5,false);
     int res=lastSearch-firstSearch+1;

     printf("  %d ",res);
   }

    return 0;
}



int binarySearch(int arr[], int size, int x, bool searchFirst){


   int low=0, high=size-1;
   int mid=(low+high)/2;
   int result=-1;

   while(low<high){

    if(arr[mid]==x){
        result=mid;

        if(searchFirst)
            high=mid-1;
        else
            low=mid+1;
    }
    else if(arr[mid]<x) low=mid+1;
    else low=high=mid-1;

   }
   return result;
}


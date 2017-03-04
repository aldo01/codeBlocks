#include<stdio.h>
#include<stdlib.h>
// A divide and conquer based efficient solution to find median
// of two sorted arrays of same size.
#include<bits/stdc++.h>
using namespace std;


int countMedian(int [], int [], int);
int median(int [], int);

  int main(){
   int arr1[]={1, 2, 3, 6};
   int arr2[]={4, 6, 8, 10};

    int size=sizeof(arr1)/sizeof(arr1[0]);
    printf("median is %d ", countMedian(arr1,arr2,size));

    return 0;
  }

  int countMedian(int arr1[], int arr2[], int n){

     if(n<0)
        return -1;
     if(n==1)
        return (arr1[0]+arr2[0])/2;

     if(n==2)
        return (max(arr1[0],arr2[0])+min(arr1[1],arr2[1]))/2;

     int m1=median(arr1,n);
     int m2=median(arr2,n);

     if(m1<m2)
       if(n%2==0)
        return (countMedian(arr1+n/2-1, arr2, n-n/2+1));
     return (countMedian(arr1+n/2,arr2,n-n/2));

     if(m1>m2){

        if(n%2==0)
            return (countMedian(arr2+n/2-1,arr1,n-n/2+1));
        return (countMedian(arr2+n/2,arr1,n-n/2));
     }

  }

  int median(int arr[], int n)
{
    if (n%2 == 0)
        return (arr[n/2] + arr[n/2-1])/2;
    else
        return arr[n/2];
}

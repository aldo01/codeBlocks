/**
   An interval is represented as a combination of start time and end time. Given a set of intervals,
   check if any two intervals overlap.

Input:  arr[] = {{1,3}, {5,7}, {2,4}, {6,8}}
Output: true
The intervals {1,3} and {2,4} overlap


Input:  arr[] = {{1,3}, {7,9}, {4,6}, {10,13}}
Output: false
No pair of intervals overlap.

Expected time complexity is O(nLogn) where n is number of intervals.

   @author Nimish

**/

#include<stdio.h>
#include<algorithm>
#include<iostream>
 using namespace std;

  struct interval{
   int start;
   int end;
  };

  bool Isoverlap( interval [],int);

 int main(){
  interval  arr1[]={{1,3}, {7,9}, {4,6}, {10,13}};
  int n= sizeof(arr1)/sizeof(arr1[0]);
  printf("%d",Isoverlap(arr1,n));
  return 0;
 }

bool compareInterval(interval i1, interval i2)
{  return (i1.start < i2.start)? true: false; }

 bool Isoverlap(interval arr1[],int n){
   sort(arr1,arr1+n-1,compareInterval);
   for(int i=i;i<n;i++){
    if(arr1[i-1].end>arr1[i].start)
     return true;

     return false;
   }
 }




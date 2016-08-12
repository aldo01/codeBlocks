#include<stdio.h>
#include<iostream>

#define MAx 19
int main(){
  enum days {MON,TUE,WED=6,THR,FRI=1,SAT};
  printf("%d%d%d%d%d%d\n",MON,TUE,WED,THR,FRI,SAT);

  int i=10;

  //printf("%d nos is y",i);
  int _=10;
  int __=5;
  int ___;
  ___=__-_;
  //printf("%i ",___);
  short arr[4][3]={{1},{2,3},{4,5,6}};
  printf("%d",sizeof(arr));
  int e = sizeof(_);
  printf("%d",e);
  alignof(e);
  return 0;
  }

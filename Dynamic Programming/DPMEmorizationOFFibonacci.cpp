
// MEMORIZED(TOP DOWNU) APPROACH FOR FIBONACCI USING DP....


#include<stdio.h>
#define MAX 50
#define NIL -1

 int LookUp[MAX];
 int initialize();
 int fib(int);

 int main(void){
  int n=1;
  initialize();
  printf("%d",fib(n));
  return 0;
 }

 int initialize(){

  int i;
  for(i=0;i<MAX;i++)
    LookUp[i]=NIL;
 }

 int fib(int n){
  if(LookUp[n]=NIL){
   if(n<=1)
    LookUp[n]=n;
    else
      LookUp[n]=fib(n-1)+fib(n-2);

  }
    return LookUp[n];
 }

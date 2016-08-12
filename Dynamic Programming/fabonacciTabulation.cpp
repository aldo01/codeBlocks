#include<stdio.h>
unsigned long int fib(int);
  int main(void){
 unsigned long int n=100;
  printf("%lu",fib(n));
  return 0;

 }

 unsigned long int fib( int n){
   int f[n+1],i;
   f[0]=0;
   f[1]=1;
   for(i=2;i<=n;i++)
    f[i]=f[i-1]+f[i-2];
    return f[n];
 }

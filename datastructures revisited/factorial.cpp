#include<stdio.h>
unsigned long int factorial(int);

 int main(void){
  //int n=4;
  printf("%d",factorial(20));
 }

unsigned long int factorial(int n){
 if(n==0)
   return 1;

 else
   return n*factorial(n-1);
}

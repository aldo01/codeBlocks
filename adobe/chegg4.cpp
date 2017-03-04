#include<stdio.h>
int f(int );
int main(){
  int n=3;
   printf("%d",f(n));

}

  int f(int n){

  if(n==1)
      return 2;

    if(n==2)
       return 3;

   else
      return 8*f(n-1)-15*f(n-2) ;

  }

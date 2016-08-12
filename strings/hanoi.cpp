#include<stdio.h>

int toh(int,char,char,char);
  int main(){
   int n;
   printf("enter the nos of plates :");
   scanf("%d",&n);
   toh(n-1,'a','b','c');
   return(0);
  }

int toh(int n,char x,char y,char z){
  if(n>0){

   toh(n-1,x,z,y);
   printf("\n%c->%c",x,y);
   toh(n-1,z,y,x);
  }

}

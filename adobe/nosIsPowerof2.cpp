#include<stdio.h>


bool isPower(int);
int main(){

 int n=16;
 printf(" %d ",isPower(n));
 return 0;
}

  bool isPower(int n){
   return n && (!(n&(n-1)));
  }

#include<stdio.h>
#include<stdlib.h>
  int SumDiv(int);
 int main(void){

   int num;
   scanf("%d",&num);
   int s=SumDiv(num);
   if(num%s==0)
    printf("yes");
   else
    printf("NO");
   return 0;
 }

 int SumDiv(int n){
      int sum=0;
      int num=n;
      while(num!=0){
       int rem=num%10;
       sum=sum+rem;

      num= num/10;

      }
      return sum;
 }


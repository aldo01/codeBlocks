#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int primeFactors(int);
int main(){
  int n;

scanf("%d",&n);
printf("%d\n",sqrt(n));
primeFactors(n);
return 0;
 }

int primeFactors(int n){
 while(n %2==0){
   printf("%d\n",2);
   n=n/2;
 }


   for(int i=3;i<=(n/2);i=i+2){
     while(n %i==0){
      printf("%d\n",i);
      n=n/i;
      }
   }
   if(n>0)
   printf("%d\n",n);
 }



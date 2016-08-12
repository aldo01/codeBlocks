#include<stdio.h>
#include<stdlib.h>

int main()
{
 int num,t;
 int count  =0;
 int digit;
 scanf("%d\n",&t);
 while(t--){
 scanf("%d\n",&num);
  int digit=num%10;
  //num/10;
  if(digit==0)
   continue;
   if(num%digit==0)count++;

   num/10;

 }
printf("%d",count);
}

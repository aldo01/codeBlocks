#include<stdio.h>
int print1();
int print2();
int main(){
 char a[10]="hhh";
 char b[10]="hhh";
 if(a==b)
   printf("nkfndknfk");

   print1();
   print1();
   print2();
   print2();
 return 0;
}

int print1(){
 static int x=10;
 x +=5;
 printf("%d ",x);
}

int print2(){
static int x;
x=10;
x+=5;
printf("%d ",x);
}


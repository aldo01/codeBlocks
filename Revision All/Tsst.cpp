#include<stdio.h>
int sum(int *,int *);
int main(){
 int a=5,b=10;

 a= sum(&a,&b);
 a= sum(&a,&b);
 printf("%d",a);
 return 0;
}

int sum(int *x,int *y){
 int c;
 c=*x+*y;
 return c;
}

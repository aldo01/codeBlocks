#include<stdio.h>

int makeit(int,int,int);

int main(){
int a =5;
int b=10;
makeit(b,a,a+b);
printf("%d %d",a,b);
return 0;
}
int makeit(int x, int y ,int z){
 x*=y+z;
 y=x<<1;
 z=x+y;
}

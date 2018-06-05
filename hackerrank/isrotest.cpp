#include<stdio.h>
int pot(int *, int *);
int main(){
 int n=30;
 pot(&n,&n);
 printf("%d ",n);
}

int pot(int *x, int *y){

  *x=(*x) * --(*y);
}

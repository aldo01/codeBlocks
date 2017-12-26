#include<stdio.h>
int f(int *, int *);
int main(){
  int i=2, j=5;
  f(&i,&j);
  //printf("%d %d",i,j);

return 0;
}

int f(int *p, int *q){
  //q=p;
  printf("%d %d",*p,*q);
  //*p=2;
  //*q=3;
}

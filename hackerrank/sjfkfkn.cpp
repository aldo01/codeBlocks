#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
#include<iostream>
  using namespace std;


struct container{
  int x;
};

 int swap1(struct container *, struct container *);
int main(){
     struct container a;
     a.x=34;
     struct container b;
     b.x=76;

     swap1(&a,&b);

     printf("%d %d ",a.x,b.x);
}

int swap1(struct container *a, struct container *b){
 struct container *temp;
 temp=b;
 b=a;
 a=temp;
}

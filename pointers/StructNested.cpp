
// OFFSET OF AN STRUCTURE ELEMENT;;;;;

#include<stdio.h>


 struct a{
   struct b{
    int i;
    float f;
    char ch;
   }x;
   struct c{
     int i;
     float g;
     char ch;
   }y;
 }z;
 int fun(struct *x);

  int main(){
  struct a x;
  int *p;
  fun(&z.x);
  printf("%d%f%s\n",z.x.i,z.x.f,z.x.ch);
  return 0;

   }

   int fun(struct b *p ){
    int offset;
    struct b *address;

    adress->i=400;
    address->f=3.12;
    address->ch='d';

}



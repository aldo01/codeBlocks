#include<stdio.h>
 #define PIE 3.14

 int CalcAreaPeri(int,float *,float *);

 int main(){
 int radius;
 float area,peri;
  printf("enter the rdius");
  scanf("%d",&radius);
   CalcAreaPeri(radius,&area,&peri);
   printf("Area is %f:",area);
   printf("perimeter is %f:",peri);
 }
  int CalcAreaPeri(int r,float *a,float *b){
      *a=PIE*r*r;
      *b=2*PIE*r;
  }

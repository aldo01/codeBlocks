#include<stdio.h>



int main(void){
static int i;
for(++i;++i;++i){
  printf("%d",i);
  if(i==4) break;
}
 return 0;
}

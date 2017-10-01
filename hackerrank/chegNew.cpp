#include<stdio.h>
#include<string.h>
#include<malloc.h>

int main(){

int *p;
int l=p,k;
k=realloc(p,2*sizeof(char));
printf("%d ",k);

return 0;

}

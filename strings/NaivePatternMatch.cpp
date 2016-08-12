#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int matcher(char *,char *);
int main(){
  char *txt="AABBCAABBCAA";
  char *ptr="CAA";
   matcher(txt,ptr);
   return 0;
}

int matcher(char *txt,char *ptr){
  int N = strlen(txt);
  int M = strlen(ptr);
  int i,j;
   for(i=0;i<=N-M;i++){
    for(j=0;j<M;j++){
      if(txt[i+j]!=ptr[j])
        break;
    }
    if(j==M)
      printf("match found at %d \n",i);
   }
}

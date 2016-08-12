#include<stdio.h>
#include<stdlib.h>
int permute(char *,int,int);
int swap(char *,char *);
int main(){
 char str[]="ABC";
 permute(str,0,2);
 getchar();
 return 0;
}

int permute(char *str,int s,int e){
 int j;
 if(s==e)
  printf("%s\n",str);
  else{
   for(j=s;j<=e;j++){
     swap((str+s),(str+j));
     permute(str,s+1,e);
     swap((str+s),(str+j));
   }
  }
}
int swap(char *a,char *b){
 char temp;
 temp=*a;
 *a=*b;
 *b=temp;
}

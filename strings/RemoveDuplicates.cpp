#include<stdio.h>
#include<stdlib.h>
#define NO_OF_CHAR 256
char *removeDuplicate(char *);
int main(){
 char str[]="geeksforgeeks";
 printf("%s",removeDuplicate(str));
 getchar();
 return 0;
}

char *removeDuplicate(char *str){
  bool bin_hash[NO_OF_CHAR]={0};
  int ip_idx=0,res_idx=0;
  while(*(str+ip_idx)){
 char  temp=*(str+ip_idx);
   if(bin_hash[temp]==0){
    bin_hash[temp]=1;
    *(str+res_idx)=*(str+ip_idx);
    res_idx++;
   }
   ip_idx++;
  }
  *(str+res_idx)='\0';
  return str;
}

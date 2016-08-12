#include<stdio.h>
#include<stdlib.h>
#include<string>

#define NO_OF_CHAR 256

int *getCharCount(char *);
char *removeDirtyString(char *,char *);

int main(){
 char mask_str[]="mask";
 char str[]="geeksforgeeks";
 printf("%s",removeDirtyString(str,mask_str));
 getchar();

 return 0;
}

char *removeDirtyString(char *str,char *mask_str){
 int *count= getCharCount(mask_str);
 int ip_idx=0,res_idx=0;
 char temp;

 while(*(str+ip_idx)){
  temp=*(str+ip_idx);
  if(count[temp]==0){
   *(str+res_idx)= *(str+ip_idx);
   res_idx++;
  }
   ip_idx;
 }
   *(str+res_idx)='\0';
   return str;

}

int *getCharCount(char *str){
 int *count =(int *)calloc(sizeof(int),NO_OF_CHAR);

 int i;
 for(i=0;*(str+i);i++)
  count[*(str+i)]++;
  return count;
}


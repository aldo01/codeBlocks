#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
# include <string.h>

bool isrotation(char *, char *);

int main(){
 char *str1="ABCD";
 char *str2="CDAB";
  printf(" %d " , isrotation(str1,str2));

  return 0;
}

 bool isrotation(char *str1, char *str2){
      int size1   = strlen(str1);
  int size2   = strlen(str2);
    if(size1 != size2)
        return 0;

  char *ptr;
   char *temp=(char *)malloc(sizeof(char )*(size1*2+1));
   strcat(temp,str1);
   strcat(temp, str1);

   ptr=strstr(temp,str2);

   if(ptr!=NULL)
      return 1;

   return 0;
 }

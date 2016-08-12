#include<stdio.h>
#include<string.h>
#include<stdlib.h>

bool isRotation(char *,char *);

int main(){
  char *str1="ABCD";
  char *str2="CDAB";
 // char *temp=strcat(str1,str2);
  //printf("%s",strcat(str1,str2));
  if(isRotation(str1,str2))
    printf("str1 is rotation of str2");
  else
     printf("not rotarion");

     getchar();
     return 0;

}
bool isRotation(char *str1,char *str2){
  int size1=strlen(str1);
  printf("%d",size1);
  int size2=strlen(str2);
  if(size1!=size2)
   return 0;

   char *temp=(char *)malloc(sizeof(char)*(size1*2+1));
   strcat(temp,str1);
   printf("%s",temp);
   strcat(temp,str1);
  // printf("%s",temp);
   void *ptr=strstr(temp,str2);
   free(temp);
   if(ptr!=NULL)
    return 1;

    return 0;
}


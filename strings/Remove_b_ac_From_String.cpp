#include<stdio.h>
#include<stdlib.h>
#include<string.h>
bool isNext(char *,int);

 /*int removeB_AC(char *str){
  int i;
  for(i=0;str[i]!='\0';i++){
  if(str[i]=='b' || str[i]=='a')
     {
        if(str[i]=='b'){
         memmove(str[i],str[i+1],strlen(str)-i);
        // str[i]++;
         //break;
        }
        if(str[i]=='a'){
         isNext(str,i);
         if(isNext){
          memmove(str[i],str[i+1],strlen(str)-i);
          memmove(str[i+1],str[i+2],strlen(str)-(i+1));


         }
        }
     }
  }
 }*/
 int main(){
  char str[]="acbd";
  //printf("%s",str);
  int i;
  for(i=0;str[i]!='\0';i++){
  if(str[i]=='b' || str[i]=='a')
     {
        if(str[i]=='b'){
         memmove(&str[i],&str[i+1],strlen(str)-i);
        // str[i]++;
         break;
        }
        if(str[i]=='a'){
         isNext(str,i);
         if(isNext){
          memmove(&str[i],&str[i+1],strlen(str)-i);
          memmove(&str[i],&str[i+1],strlen(str)-i);


         }
        }
     }
    // printf("%c",str[i]);
  }

   printf("%s",str);

  return 0;
 }
bool isNext(char *str,int index){
 if(str[index+1]=='c')
  return true;

  return false;
}

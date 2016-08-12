#include<stdio.h>
#include<string.h>
int reverseWord(char *);
int reverse(char *,char *);

 int main(){
  char s[]=" nimish karan is a good boy";
  char *temp=s;
  reverseWord(s);
  printf("%s",s);
  getchar();
  return(0);

 }
 int reverseWord(char *s){
  char *word_begin=s;
  char *temp=s;
   while(*temp){
    temp++;
    if(*temp=='\0'){
      reverse(word_begin,temp-1);
    }
    else if(*temp==' '){
     reverse(word_begin,temp-1);
     word_begin=temp+1;
    }

   }
    reverse (s,temp-1);
 }

 int reverse(char *begin,char *end){
   char temp;
   while(begin<end){
     temp=*begin;
     *begin++=*end;
     *end--=temp;
   }
 }

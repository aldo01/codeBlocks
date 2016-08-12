#include<stdio.h>
#include<string.h>

int splitString(char *str,int n){
 int len=strlen(str);
 if(len%n!=0)
   return 0;
   int i;
   int part_size=len/n;
   for(i=0;i<len;i++){
     if(i%part_size==0)
      printf("\n");

      printf("%c",str[i]);
   }

}
int main(){
 char str[]="a_simple_divide_string_quest";
 splitString(str,4);
 getchar();
 return 0;
}

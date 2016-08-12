#include<stdio.h>
#include<stdlib.h>
#define NO_OF_CHARS 256
#define MAX 50

int *getArrayCount(char *);
int encode(char *);

int *getArrayCount(char *str){
int *HashMap=(int *)calloc(sizeof(int),NO_OF_CHARS);
int i;
for(i=0;*(str+i);i++)
  HashMap[*(str+i)]++;
  return HashMap;
}

int encode(char *str){
int *map= getArrayCount(str);
char dest[MAX];
int i=0;
while(*(str+i)!='\0' && map){
//int i=0;
  dest[i]=str[i];
  if(dest[i])
  printf("%c%d",dest[i],map[*(str+i)]);
  map[*(str+i)]=0;
  i++;
}
}
int main(){
 char str[]="abcdd";
 encode(str);
 return 0;
}

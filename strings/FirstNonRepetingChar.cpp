#include<stdio.h>
#include<stdlib.h>
#define NO_OF_CHAR 256

int *getArrayCount(char *str){
  int *count =(int *)calloc(sizeof(int),NO_OF_CHAR);
  int i;
  for(i=0;*(str+i);i++)
   count[*(str+i)]++;

   return count;
}

int firstNonRepeating(char *str){
  int *count = getArrayCount(str);
  int i;
  int index=-1;
  for(i=0;i<NO_OF_CHAR;i++){
    if(count[i]==1){
      index=i;
      break;
    }

  }
  free(count);
  return index;
}

int main(){
 char *str="geeksquiz";
 int index =firstNonRepeating(str);
 if(index==-1)
  printf("all char are repeting or string is null");
  else
   printf("first non repeting charactr is %c",index);

   return 0;

}


#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define NO_OF_CHAR 256

struct countindex{
 int count;
 int index;
};

 struct countindex *getArrayCount(char *);
 int firstNonRepeating(char *);
 //.....................................
struct countindex *getArrayCount(char *str){
  struct countindex *node=(struct countindex *)calloc(sizeof(struct countindex),NO_OF_CHAR);
  int i;
  for(i=0;*(str+i);i++){
    (node[*(str+i)].count)++;

    // if first occurrencr then save the index

    if(node[*(str+i)].count==1)
     node[*(str+i)].index=i;
  }
  return node;

}
int firstNonRepeating(char *str){
 int result=INT_MAX;
 int i;
  struct countindex *node=getArrayCount(str);
  for(i=0;i<NO_OF_CHAR;i++){
    if(node[i].count==1 && result>node[i].index)
    result=node[i].index;
}
free(node);
return result;
}

int main(){
 char str[]="geeksforgeeks";
 int index=firstNonRepeating(str);
 if(index==INT_MAX)
   printf("either all char are repeating or string is empty");
   else
    printf("fist non repeating char is %c",str[index]);

    getchar();
    return 0;


}

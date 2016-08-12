#include<stdio.h>
#include<stdlib.h>
char getMaxoccur(char *);
int *getCharCount(char *);
char getMaxIndex(int[] ,int);

int main(){
 char str []="nnnaa";
 printf("%c",getMaxoccur(str));
 getchar();
 return 0;
}
 char getMaxoccur(char *str){
int *count =getCharCount(str);
return getMaxIndex(count,256);
}
int *getCharCount(char *str){
 int *count=(int*)calloc(256,sizeof(int));
 int i;
 for(i=0;*(str+i);i++)
   count[*(str+i)]++;
   return count;
}

char getMaxIndex(int arr[],int arr_size){
int Max_index=0;
int i;
 for(i=1;i<arr_size;i++){
  if(arr[i]>arr[Max_index])
  Max_index=i;
 }
 return Max_index;
}

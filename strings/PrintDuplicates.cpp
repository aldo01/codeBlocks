#include<stdio.h>
#include<stdlib.h>
#define NO_OF_CHAR 256

int printDup(char *);
int fillArrayCount(char *,int *);

int main(){
 char arr[]="test string";
 printDup(arr);

 getchar();
 return 0;
}
int printDup(char *arr){
int *count =(int *)calloc(NO_OF_CHAR,sizeof(int));
fillArrayCount(arr,count);
int i;
for(i=0;i<NO_OF_CHAR;i++){
 if(count[i]>1)
 printf("%c ,count= %d\n",i,count[i]);
}
free(count);



}

int fillArrayCount(char *arr,int *count){
 int i;
 for(i=0;*(arr+i);i++)
   count[*(arr+i)]++;
   }

#include<stdio.h>
#include<malloc.h>
# define NO_OF_CHAR 256
int main(){
char *str;
int t;
scanf("%d",&t);


    scanf("%s",&str);

    primeString(str);


}
int *getArrayCount(char *str){
  int *count =(int *)calloc(sizeof(int),NO_OF_CHAR);
  int i;
  for(i=0;*(str+i);i++)
   count[*(str+i)]++;

   return count;
}
 int primeString(char *str){
  int *count= getArrayCount(str);

  int i=0;
  for(i=0;i<256;i++){

     for(j=2;j<count[i]/2;j++){
        if(count[i]%i==1)

     }
  }
 }


#include<stdio.h>
#include<string.h>
int atoi(char *);
int main(){
 char s[]="12345";
  int n=atoi(s);
 n=  n+10;
 printf("%d",n);
 return 0;

}

int atoi(char s[])
{
 int i,n;
 n=0;
 for(i=0;s[i]>='0' && s[i]<='9';++i){
  n=10*n+(s[i]-'0');

 // return n;
 }
 return n;
}
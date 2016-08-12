#include<stdio.h>
#include<stdlib.h>
int f(struct emp);
struct emp{
 char name[20];
 int age;
};

int main(){
 union{
  int i;
  char ch[2];
 };
  struct emp e={"dss",12};
  f(e);
  return 0;
 }
 int f(struct emp ee){
  printf("%s %d",ee.name,ee.age);
 }

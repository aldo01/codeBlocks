#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
//#include<conio.h>


 struct node{
 int data;
 struct node *link;

 };

 int main(){
 int n,i;
  struct node *Head,*p;
  Head=NULL;
  printf("enter the no of items");
  scanf("%d",&n);
  Head=(node *)malloc(sizeof(node));
  scanf("%d",&(Head->data));
  Head->link=NULL;
  p=Head;

  for(i=0;i<n;i++){
 p->link=(node *)malloc(sizeof(node));
 p=p->link;
 p->link=NULL;
 scanf("%d",&(p->data));
  }

 }

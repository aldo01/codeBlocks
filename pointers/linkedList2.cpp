#include<stdio.h>
#include<malloc.h>

 typedef struct node{
 int data;
 struct node *next;
 }node;

  node * create(int);
  int print(node *);
  int count(node *);
 //start of main;
 int main(void){
  struct node *Head;
  Head=NULL;
  int n,number;
  printf("enter the nos of elements");
  scanf("%d",&n);

  Head=create(n);
  print(Head);
  number=count(Head);
  printf("\n nos od  nodes=%d",number);

 }
  node *create(int n){

  node *p,*head;
  int i;
  head=(node *)malloc(sizeof( node));
  head->next=NULL;
  scanf("%d",&(head->data));
  p=head;
   for(i=1;i<n;i++){
   p->next=(node *)malloc(sizeof(node));
   p=p->next;
   scanf("%d",&(p->data));
   p->next=NULL;

   }
   return (head);

  }
 int print(node *p){

 while(p!=NULL){
 printf("<-%d->",p->data);
 p=p->next;
 }
 }
  int count(node *p){
  int i=0;
  while(p!=NULL){
  p=p->next;
  i++;
  }
  return(i);
  }

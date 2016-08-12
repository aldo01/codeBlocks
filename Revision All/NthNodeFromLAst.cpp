#include<stdio.h>
#include<malloc.h>

struct node {
 int data;
 struct node *next;
 };

 int printLast(struct node *head,int k){
  struct node *temp=head;
   int len=0;
   int i;
int n=k;
  while(temp!=NULL){
   temp=temp->next;
   len++;
  }
  if(len<n)
   return 0;
   temp=head;
   for(i=0;i<len-n+1;i++){
    temp=temp->next;
    printf("%d",temp->data);

   }
    return 0;

 }

 int push(struct node **head_ref,int new_data){
  struct node *temp=(struct node *)malloc(sizeof(struct node ));
  temp->data=new_data;
  temp->next=*head_ref;
  *head_ref=temp;
 }
 int main(){
  struct node *head=NULL;
  push(&head,2);
   push(&head, 20);
  push(&head, 4);
  push(&head, 15);
  push(&head, 35);
  printLast(head,3);
  return 0;
 }

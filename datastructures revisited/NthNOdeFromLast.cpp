#include<stdio.h>
#include<malloc.h>
 struct node{
  int data;
  struct node *next;
 };
 int push(struct node **,int);
 int printList(struct node *);
 int NodeFromLast(struct node *,int);

 int push(struct node **head_ref,int new_data){
  struct node *temp=(struct node *)malloc(sizeof(struct node ));
  temp->data=new_data;
  temp->next=*head_ref;
  *head_ref=temp;
 }
 int NodeFromLast(struct node *head,int n){
 struct node *temp=head;
  int len  =0;
  while(temp!=NULL){
    temp=temp->next;
    len++;
   }
   if(len<n)
   return 0;
   temp=head;
   for(int i=1;i<len-n+1;i++)
    temp=temp->next;
    printf("%d",temp->data);


 }
 int main(){
  struct node *head=NULL;
  push(&head,2);
  push(&head,12);
  push(&head,4);
  push(&head,6);
  push(&head,8);
  push(&head,9);
  push(&head,7);
  printList(head);
  printf("\n.......");
  NodeFromLast(head,5);
  printf("\n");
  printList(head);
  return 0;
 }
 int printList(struct node *head){
  while(head!=NULL){
   printf(" %d ",head->data);
   head=head->next;
  }
 }

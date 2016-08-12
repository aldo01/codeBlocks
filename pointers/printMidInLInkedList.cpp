#include<stdio.h>
#include<malloc.h>
struct node{
 int data;
 struct node *next;
};
int push(struct node **,int );
int getMid(struct node **);
int printList(struct node *);
 int main(){
  struct node *head=NULL;
  push(&head,98);
  push(&head,23);
  push(&head,76);
  push(&head,12);
  push(&head,44);
  printList(head);
  printf("the mid element is %d ",getMid(&head));
  }
  int push(struct node **head_ref,int new_data){
   struct node *temp=(struct node *)malloc(sizeof(struct node));
   temp->data=new_data;
   temp->next=*head_ref;
   *head_ref=temp;

  }
  int printList(struct node *head){
  struct node *current=head;
  while(current!=NULL){
   printf(" %d ",current->data);
   current=current->next;

  }

  }
  int getMid(struct node **head){
   struct node *fast=*head;
   struct node *slow=*head;
   if(*head!=NULL){
   while(fast!=NULL&&fast->next!=NULL){
    fast=fast->next->next;
    slow=slow->next;

   }
   return(slow->data);

  }
  }

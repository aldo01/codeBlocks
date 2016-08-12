#include<stdio.h>
#include<malloc.h>



int reverse(struct node **);
int push(struct node **,int);
int printList(struct node *);

//===============================================

 struct node{
   int data;
   struct node *next;
 };
int main(){
 struct node *head=NULL;
   push(&head,21);
   push(&head,22);
   push(&head,33);
   push(&head,35);

   printList(head);
   reverse(&head);
   printf("\n");
   printList(head);
   return 0;
   }

   int reverse(struct node **head){
     struct node *result=NULL;
     struct node *current=*head;
     struct node *next;
     while(current!=NULL){
      next=current->next;
      current->next=result;
      result=current;
      current=next;

     }
     result=*head;
   }

   int push(struct node **head,int new_data){
      struct node *temp=(struct node *)malloc(sizeof(struct node));
      temp->data=new_data;
      temp->next=*head;
      *head=temp;
   }

 int printList(struct node *head){
  while(head!=NULL){
     printf("<%d>",head->data);
     head=head->next;
   }
 }

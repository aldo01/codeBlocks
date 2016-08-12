#include<stdio.h>
#include<malloc.h>

 struct node{
  int data;
  struct node *next;
 };

 int reverse(struct node **);
 int push(struct node **,int );
 int printList(struct node *);

int main(){
    struct node *head;
    push(&head,22);
    push(&head,11);
    push(&head,4);

    reverse(&head);

    printList(head);

    return 0;
}

int reverse(struct node **head){
   struct node *result=NULL;
   struct node *curr=*head;
   struct node *next;

   while(curr!=NULL){
     next=curr->next;
     curr->next=result;
     result=curr;
     curr=next;
   }
   *head=result;
  }

  int push(struct node **head,int new_data){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=new_data;
    temp->next=*head;
    *head=temp;


  }
  int printList(struct node *head){
     while(head!=NULL){
         printf(" %d ", head->data);
         head=head->next;

     }
   }

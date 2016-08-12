#include<stdio.h>
#include<malloc.h>

int reverse(struct node **);
int push(struct node **,int);
int printList(struct node *);

struct node  {
 int data;
 struct node *next;
};
int main(){
 struct node *head=NULL;
 push(&head,11);
 push(&head,22);
 push(&head,21);
 push(&head,90);

 //printList(head);
 reverse(&head);
 printList(head);

   return 0;
}
  int reverse(struct node **head){
   struct node *first;
   struct node *rest;
   if(*head==NULL)
     return 0;

     first=*head;
      rest= first->next;

     if(rest==NULL)
      return 0;
     reverse(&rest);
     first->next->next=first;
     first->next=NULL;
     *head=rest;




  }

 int push(struct node **head,int new_data){
  struct node *temp=(struct node *)malloc(sizeof(struct node ));
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

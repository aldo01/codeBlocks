#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
struct node{
 int data;
 struct node *next;
};
int delete_node(struct node *);
int push(struct node **,int);
int print(struct node *);
int main(){
  struct node* head=NULL;
  push(&head,23);
  push(&head,65);
  push(&head,11);
  push(&head,33);
  printf("before delete\n");
  print(head);
  delete_node(head);
  printf("\nafter delete\n");
  print(head);
   }

   int push(struct node **head_ref,int new_data){
     struct node *temp=(struct node*)malloc(sizeof(struct node));
     temp->data=new_data;
     temp->next=*head_ref;
     *head_ref=temp;

   }
   int print(struct node* head){
   struct node *temp=head;
   while(temp!=NULL){
     printf("%d ",temp->data);
     temp=temp->next;
   }

   }
   int delete_node(struct node *node_ptr){
    struct node *temp=node_ptr->next;
    node_ptr->data=temp->data;
    node_ptr->next=temp->next;
    free(temp);

   }

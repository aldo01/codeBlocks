#include<stdio.h>
#include<malloc.h>

  struct node{
   int data;
   struct node *next;
   struct node *prev;
  };
    int push(struct node **,int);
    int print(struct node *);

    int main(){
     struct node *head=NULL;
     push(&head,2);
     //print(head);
     push(&head,4);
     push(&head,1);
     print(head);

    }

    int push(struct node **head_ref,int new_data){
      struct node *temp1;
      temp1=(struct node *)malloc(sizeof(struct node));
      temp1->data=new_data;

      temp1->prev=NULL;
      temp1->next=*head_ref;
      if(*head_ref!=NULL)

          (*head_ref)->prev=temp1;



      *head_ref=temp1;
    }
  int print(struct node * node){
  //struct node *temp=head;
    while(node!=NULL){
      printf("%d",node->data);
      node=node->next;
    }
  }

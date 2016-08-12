#include<stdio.h>
#include<malloc.h>


  struct node{
   int data;
   struct node *next;
  };

  int push(struct node **,int );
  bool identical(struct node *,struct node *);

   int main(void){
    struct node *head1=NULL;
    struct node *head2=NULL;

     push(&head1,1);
     push(&head1,2);
     push(&head1,3);

     push(&head2,1);
     push(&head2,2);
     push(&head2,4);

      bool q = identical(head1,head2);
      printf("%d",q);

   }

   int push(struct node **head1_ref,int new_data){
     struct node *temp=(struct node *)malloc(sizeof(struct node));
     temp->data=new_data;
     temp->next=*head1_ref;
     *head1_ref=temp;

   }
   bool identical(struct node *head1,struct node *head2){
     if(head1==NULL&&head2==NULL){
        return 1;
     };
     if(head1==NULL&&head2!=NULL){
       return 0;
     }
     if(head1!=NULL&&head2==NULL){
       return 0;
     }
     if(head1->data!=head2->data){
       return 0;
     }
      return identical(head1->next,head2->next);
   }


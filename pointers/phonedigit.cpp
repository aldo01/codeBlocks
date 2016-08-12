#include<stdio.h>
#include<malloc.h>


   struct node{
     int data;
     struct node *next;

   };
    int push(struct node **,int);
    int printList(struct node *);
    int deleteList(struct node *);


    int main(){

        struct node *Head=NULL;
         push(&Head,23);
         push(&Head,12);
         push(&Head,44);
         push(&Head,91);

          //printList(Head);
          deleteList(Head);
          printList(Head);
          getchar();

    }


       int push(struct node **head,int new_data){
         struct node *temp=*head;
         temp=(struct node *)malloc(sizeof(struct node));
         temp->data=new_data;
         temp->next=*head;
         *head=temp;

       }

       int printList(struct node *Head){
          struct node *temp=Head;
          while(temp!=NULL){
           printf(" %d ",temp->data);
           temp=temp->next;
          }

        }


  int deleteList(struct node *head_ref){
    struct node *temp=head_ref->next;
             head_ref->data=temp->data;
             head_ref->next=temp->next;
             free(temp);




  }

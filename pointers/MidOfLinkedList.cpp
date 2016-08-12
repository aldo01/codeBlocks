#include<stdio.h>
#include<malloc.h>


   struct node{
   int data;
   struct node *next;
   };

   int push(struct node **,int);
   int returnMid(struct node *);



      int main(){
       struct node *Head=NULL;
       push(&Head,23);
       push(&Head,12);
       push(&Head,48);
       push(&Head,34);
       push(&Head,22);

        returnMid(Head);

      }


       int push(struct node **head,int n){
          struct node *temp=(struct node *)malloc(sizeof(struct node));
            temp->data=n;
            temp->next=*head;
            *head=temp;
            }


            int returnMid(struct node *Head){
            struct node *fast_head=Head;
            struct node *slow_head=Head;
              while (fast_head!=NULL && fast_head->next!=NULL){
               fast_head=fast_head->next->next;
               slow_head=slow_head->next;
              }
              printf("mid element is %d",slow_head->data);


            }

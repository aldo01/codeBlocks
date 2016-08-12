#include<stdio.h>
//#include<conio.h>
#include<malloc.h>

  struct node{
   int data;
   struct node *next;
  };

 int push(struct node **,int);
 int count(struct node *,int);


    int main(void){
      struct node *head;
      head=NULL;
      push(&head,1);
      push(&head,4);
      push(&head,6);
      push(&head,1);
      push(&head,1);
      push(&head,1);
      printf("nos of 1 is = %d",count(head,1));
      getchar();
    }
     int push(struct node **p ,int new_data){
       struct node *new_node;
       new_node=(struct node *)malloc(sizeof(struct node));
        new_node->data=new_data;
        new_node->next=*p;
        *p=new_node;
     }
     int count(struct node *Head,int search_for){
       struct node *current=Head;
       int count=0;
       while(current!=NULL){

         if(current->data==search_for){
           count++;
           current=current->next;
        }
       }
       return count;

     }











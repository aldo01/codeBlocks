#include<stdio.h>
#include<malloc.h>

 struct node{
  int data;
  struct node *next;
 };
  int push(struct node **,int);

    int main(){
     struct node *Head;
     push(&Head,23);
     push(&Head,12);
     push(&Head,44);
     push(&Head,32);
     push(&Head,91);
   printf("-------------------------------");
  printf("\n%d",Head->next->data);
  //insertAtFront(&Head,)


    }


  int push(struct node **head,int new_data){
  struct node *temp=*head;
     if(head==NULL){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
     temp->data=new_data;
     temp->next= *head;
     *head=temp;
     }
     printf("%d\n",temp->data);

//     printf("%d",*head->data);
  //}
   // int insertAtFront(struct node *Head,int key){
     //struct node *

     }



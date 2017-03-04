#include<stdio.h>
#include<malloc.h>


struct node{
 int data;
 struct node *next;
};
int main(){

struct node *head=NULL;
 push(&head,12);
 push(&head,13);
 push(&head,14);
 push(&head,15);

 printnList(head);

 printf("reverse list.....");

 reverseList(&head);

 printArray(head)

return 0;

}

  int push(struct node **head, int data){
    struct node *temp=(struct node *)malloc(sizeof(struct node ));

    temp->data=data;
    temp->next=*head;
    *head=temp;
  }

  int printList(struct node *head){
    while(*head!==NULL){

        printf(" %d ",head->data);

    }
  }


  int reverseList(struct node **head){
    struct node *fast=*head;
    strucct node *slow=*head;

  }

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node{
 int data;
 struct node *next;
};

 int reverse(struct node **head){
  struct node *first;
  struct node *rest;
  if(*head==NULL) return 0;

    first=*head;
    rest=first->next;
    if(rest==NULL) return 0;
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

int print(struct node *head){
 struct node *temp=head;
 while(temp!=NULL){
  printf("%d\n",temp->data);
  temp=temp->next;
 }
}
 int main(){
 struct node *head=NULL;
  push(&head,1);
 push(&head,2);
 push(&head,3);
 push(&head,4);
 print(head);
 printf("\nafter reversal\n");
 reverse(&head);
 print(head);
  return 0;
 }

#include<stdint-gcc.h>
#include<stdlib.h>
#include<stdio.h>

int push(struct node **, int);
int printList(struct node *);
struct node{
int data;
struct node *next;
};
int main(){

struct node *head=NULL;
push(&head,21);
push(&head,33);
push(&head,11);
push(&head,22);

printList(head);
return 0;
}

int push(struct node **head,int new_data){
struct node *temp=(struct node *)malloc(sizeof(struct node ));
temp->data=new_data;
temp->next=*head;
*head=temp;
}

int printList(struct node *head){
 while(head!=NULL){
 printf("<-%d->",head->data);
 head=head->next;
 }
}

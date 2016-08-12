#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
};
int push(struct node **,int);
bool isCycle(struct node **);

int main(void){
struct node *head=NULL;
push(&head,23);
push(&head,43);
push(&head,2);
push(&head,6);
push(&head,12);
push(&head,5);
head->next->next->next->next->next->next=head->next->next;

bool res=isCycle(&head);
printf("%d",res);

}
bool isCycle(struct node **head_ref){
struct node *fast=*head_ref;
struct node *slow=*head_ref;
//base case;;;;


while(fast!=NULL){
  slow=slow->next;
  fast=fast->next->next;
  if(slow==fast)
  return(1);
  }

  return 0;

}

int push(struct node **head_ref,int new_data){
struct node *temp=(struct node *)malloc(sizeof(struct node ));
temp->data=new_data;
temp->next=*head_ref;
*head_ref=temp;

}

int printList(struct node *node){
 while(node!=NULL){

  printf(" %d ",node ->data);
  node=node->next;
 }

}

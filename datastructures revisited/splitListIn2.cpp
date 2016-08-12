#include<stdio.h>
#include<malloc.h>

struct node {
 int data;
 struct node *next;
};
int push(struct node **,int);
int splitList(struct node *,struct node **,struct node **);
int print(struct node *);

int push(struct node **head ,int new_data){

 struct node *temp=(struct node *)malloc(sizeof(struct node));
 temp->data=new_data;
 temp->next=*head;
 *head=temp;

}
int splitList(struct node *head, struct node **head1,struct node **head2){
 struct node *fast=head;
 struct node *slow=head;
 while(fast!=NULL && fast->next->next!=NULL){
  fast=fast->next->next;
  slow=slow->next;
 }
 *head2=slow->next;
 slow->next=NULL;
 *head1=head;
}

int print(struct node *head_ref){
struct node *ptr=head_ref;
 while(ptr!=NULL){
  printf("%d", ptr->data);
  ptr=ptr->next;
 }
}
int main(){
 struct node *head=NULL;
 struct node *head1=NULL;
 struct node *head2=NULL;
 push(&head,2);
 push(&head,4);
 push(&head,1);
 push(&head,3);
 print(head);
 printf("\n");
 splitList(head,&head1,&head2);
 print(head1);
 printf("\n");
 print(head2);
}

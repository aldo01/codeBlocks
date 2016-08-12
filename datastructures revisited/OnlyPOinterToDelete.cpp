#include<stdio.h>
#include<malloc.h>

 struct node {
  int data;
  struct node *next;
 };

 int deleteNode(struct node *);
 int push(struct node **,int);
 int printList(struct node *);

 int push(struct node **head_ref,int new_data){
  struct node *temp=(struct node *)malloc(sizeof(struct node ));
  temp->data=new_data;
  temp->next=*head_ref;
  *head_ref=temp;
 }

int deleteNode(struct node *ptr){
 struct node *temp=ptr->next;
 ptr->data=temp->data;
 ptr->next=temp->next;
 free(temp);
}
int main(){
 struct node *head=NULL;
 push(&head,1);
 push(&head,12);
 push(&head,4);
 push(&head,3);
 printList(head);
 printf("\n");
 deleteNode(head->next->next);
 printList(head);
 return 0;
}

int printList(struct node *head){
 while(head!=NULL){
  printf(" %d ",head->data);
  head=head->next;
 }
}

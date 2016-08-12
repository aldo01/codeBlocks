#include<stdio.h>
#include<malloc.h>

struct node {
int data;
struct node *next;
};
int push(struct node **,int);
bool isCycle(struct node *);

  bool isCycle(struct node *head_ref){
   struct node *fast=head_ref;
   struct node *slow=head_ref;

    while(slow && fast && fast->next){
     slow=slow->next;
     fast=fast->next->next;
     if(slow==fast){
     printf("cycle found");
     return 1;}

    }
    return 0;
  }
 int push(struct node **head,int new_data){
 struct node *temp=(struct node *)malloc(sizeof(struct node ));
 temp->data=new_data;
 temp->next=*head;
 *head=temp;
 }
 int main(){
  struct node *head=NULL;
  push(&head, 10);
    push(&head, 4);
    push(&head, 15);
    push(&head, 20);
    push(&head, 50);
    //isCycle(&head);
    /* Create a loop fr testing */
    head->next->next->next->next->next = head->next->next;
   printf("%d",isCycle(head));
    return 0;
 }

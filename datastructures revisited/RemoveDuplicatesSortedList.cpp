#include<stdio.h>
#include<malloc.h>
 struct node{
  int data;
  struct node *next;
 };
 int push(struct node **,int);
 int removeDup(struct node *);
 int print(struct node *);

 int push(struct node **head_ref,int new_data){
 struct node *temp=(struct node *)malloc(sizeof(struct node ));
 temp->data=new_data;
 temp->next=*head_ref;
 *head_ref=temp;
 }

int removeDup(struct node *head){
 struct node *current=head;
 struct node *next_next;
 if(current==NULL)
   return 0;
   while(current->next!=NULL){
    if(current->data==current->next->data){
    next_next=current->next->next;
    free(current->next);
    current->next=next_next;
    }
    else{
     current=current->next;
    }
   }
}

int main(void){
struct node *head=NULL;
push(&head,12);
push(&head,14);
push(&head,14);
push(&head,23);
removeDup(head);
print(head);
return 0;

}

int print(struct node *head){
while(head!=NULL){
 printf("%d ",head->data);
 head=head->next;
}
}

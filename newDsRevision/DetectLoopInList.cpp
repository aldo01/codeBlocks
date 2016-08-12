#include<stdio.h>
#include<stdlib.h>


int push(struct node **,int);
bool isLoop(struct node *);
int printList(struct node *);


struct node {
int daata;
struct node *next;
};
int main(){
struct node  *head=NULL;

push(&head,23);
push(&head,43);
push(&head,2);
push(&head,6);
push(&head,12);
push(&head,5);
head->next->next->next->next->next->next=head->next->next;
printf("%d", isLoop(head));

return 0;

}

int push(struct node **head,int new_data){
  struct node *temp=(struct node *)malloc(sizeof(struct node *));
  temp->daata=new_data;
  temp->next=*head;
  *head=temp;

}
int printList(struct node  *head){
while(head!=NULL){
printf(" %d ",head->daata);
head=head->next;
}
}
bool isLoop(struct node *head){
 struct node *slow=head;
 struct node *fast=head;
 while(fast!=NULL){
   slow=slow->next;
   fast=fast->next->next;
   if(slow==fast){
    return 1;
   }
 }
return 0;
}

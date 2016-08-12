#include<stdio.h>
#include<malloc.h>

 struct node {
  int data;
  struct node *next;
 };

 int CountList(struct node *head,int data1){
  int count =0;
   struct node *temp=head;
   while(temp!=NULL){
    if(temp->data==data1){
      count++;
      temp=temp->next;
    }
    //temp=temp->next;
   }
   return count;
 }

  int push(struct node **head,int new_data){
   struct node *temp=(struct node *)malloc(sizeof(struct node ));
   temp->data=new_data;
   temp->next=*head;
   *head=temp;
  }
  int main(){
   struct node *head=NULL;
   push(&head,2);
   push(&head,3);
   push(&head,2);
   push(&head,5);
   push(&head,2);
   printf("%d",CountList(head,2));
   return 0;
  }

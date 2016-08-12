#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
int push(struct node **,int);
int print(struct node *);
int getNos(struct node *,int);
struct node{
int data;
struct node *next;
};
int main(){
 struct node *head=NULL;
 push(&head,21);
 push(&head,43);
 push(&head,11);
 push(&head,9);
 push(&head,98);
 print(head);
 int x=getNos(head,3);
 printf("the nos at index is %d",x);

}
int push(struct node **head_ref,int new_data){
 struct node *temp=(struct node*)malloc(sizeof(struct node));
 temp->data=new_data;
 temp->next=*head_ref;
 *head_ref=temp;
}
int print(struct node *head){
 struct node *temp=head;
 while(temp!=NULL){
  printf(" %d ",temp->data);
  temp=temp->next;
 }
 }
int getNos(struct node *head,int index){
  int count=0;
 struct node *current=head;
  while(current!=NULL){
    if(count==index){

      return(current->data);
      count++;
      current=current->next;

    }


 }
assert(0);
}

#include<stdio.h>
#include<malloc.h>

using namespace std;

struct node{
 int data;
 struct node *next;
 struct node *prev;
};
int reverse(struct node **);
int push(struct node **,int);
int printList(struct node *);

int reverse(struct node **head)
{

}

int push(struct node **head, int new_data){
  struct node *temp=(struct node *)malloc(sizeof(struct node));
  temp->data=new_data;
  temp->next=*head;
  temp->prev=NULL;
  if(*head!=NULL){
    (*head)->prev=temp;
  }

   *head=temp;
}

int printList(struct node *head){
  while(head!=NULL){
    printf(" %d ",head->data);
    head=head->next;
  }
}
int main(){
struct node *head;
push(&head,22);
push(&head,33);
push(&head,44);
push(&head,55);

 printList(head);

 return 0;
}

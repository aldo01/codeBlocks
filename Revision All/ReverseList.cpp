#include<stdio.h>
#include<malloc.h>

struct node{

 int data;
 struct node *next;

};

int push(struct node **,int);

 int reverseList(struct node **);
  int print(struct node *);

 int reverseList(struct node **head){
 struct node *result=NULL;
 struct node *current=*head;
 struct node *next;
 while(current!=NULL){
   next=current->next;
   current->next=result;
   //result=current->next;
    result=current;
   current=next;
 }
  *head=result;
}

int main(){
// printf("hello");
 struct node *head=NULL;
 push(&head,1);
 push(&head,2);
 push(&head,3);
 push(&head,4);
 print(head);
 printf("after reversal\n");
 reverseList(&head);
 print(head);
 getchar();
 return 0;
}

  int push(struct node **head, int new_data){
struct node *temp=*head;
temp=(struct node *)malloc(sizeof(struct node ));
temp->data=new_data;
temp->next=*head;
*head=temp;
}

int print(struct node *head){
 struct node *temp=head;
 while(temp!=NULL){
  printf("%d",temp->data);
   temp=temp->next;
 }
}

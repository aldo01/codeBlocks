#include<stdio.h>
#include<malloc.h>
 struct node {
  int data;
  struct node *next;
 };
 int DeleteList(struct node **);
 int push(struct node **,int);
 int printList(struct node *);

 int push(struct node **head_ref,int new_data){
  struct node *temp=(struct node *)malloc(sizeof(struct node ));
  temp->data=new_data;
  temp->next=*head_ref;
  *head_ref=temp;
 }

int DeleteList(struct node **head){
 struct node *current=*head;
 struct node *next;
  while(current!=NULL){
   next=current->next;
   free(current);
   next=current;
    }
    *head=NULL;

}
int printList(struct node *head){
  while(head!=NULL){
   printf("%d",head->data);
   head=head->next;
  }
 }

int main(){
struct node *head=NULL;
   push(&head, 1);
    push(&head, 4);
    push(&head, 1);
    push(&head, 12);
    push(&head, 1);
    printList(head);
    printf("create");
    DeleteList(&head);
    getchar();
    return 0;
}

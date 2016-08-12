#include<stdio.h>
#include<malloc.h>

struct node{
 int data;
 struct node *next;
};

int push(struct node **,int);
int removeDup(struct node *);
int printList(struct node *);


int push(struct node **head, int new_data){
 struct node *temp=(struct node *)malloc(sizeof(struct node));
 temp->data=new_data;
 temp->next=*head;
 *head=temp;

}
int main()
{
  struct node *head;

  push(&head,1);
  push(&head,1);
  push(&head,2);
  push(&head,22);
  push(&head,2);

  removeDup(head);
  printList(head);
  return 0;
}

int removeDup(struct node *head){
 struct node *ptr1,*ptr2,*dup;
 ptr1=head;
 while(ptr1!=NULL && ptr1->next!=NULL){
    ptr2=ptr1;
    while(ptr2->next!=NULL){
        if(ptr1->data==ptr2->next->data){
            dup=ptr2->next;
            ptr2->next=ptr2->next->next;
            free(dup);
        }
        else
            ptr2=ptr2->next;
    }

 }
   ptr1=ptr1->next;
}

int printList(struct node *head){
 while(head!=NULL){
    printf("%d ",head->data);
    head=head->next;

 }
}

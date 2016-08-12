#include<stdio.h>
#include<malloc.h>

 struct node{
  int data;
  struct node *next;
 };

 int RemoveDup(struct node *head){
 struct node *ptr1, *ptr2, *dup;
  ptr1=head;
  while(ptr1!=NULL && ptr1->next!=NULL){
    ptr2=ptr1;
     while(ptr2->next!=NULL){
       if(ptr1->data==ptr2->next->data){
        dup=ptr2->next;
        ptr2->next=ptr2->next->next;
        free(dup);
       }
       else{ ptr2=ptr2->next;}
     }
  }
    ptr1=ptr1->next;
  }
int push(struct node **head, int new_data){
 struct node *temp=(struct node *)malloc(sizeof(struct node ));
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
  int main(){
   struct node *head=NULL;
   push(&head,2);
   push(&head,4);
   push(&head,1);
   push(&head,2);
   push(&head,7);
   print(head);
   printf("\nafter duplicate\n");
   RemoveDup(head);
   print(head);
   return 0;
  }

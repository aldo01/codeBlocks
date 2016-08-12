#include<stdio.h>
#include<malloc.h>

 struct node {
  int data;
  struct node *next;
 };
 int push(struct node **,int);
 int RemoveDuplicate(struct node *);
 int print(struct node *);

 int RemoveDuplicate(struct node *head){
 struct node *ptr1,*ptr2,*dup;
 ptr1=head;
 while(ptr1 !=NULL && ptr1->next!=NULL){
  ptr2=ptr1;
  while(ptr2->next!=NULL){
  if(ptr1->data == ptr2->next->data){
   dup=ptr2->next;
   ptr2->next=ptr2->next->next;
   free(dup);
  }
  else{
   ptr2=ptr2->next;
   // ptr1=ptr1->next;
  }


}
ptr1=ptr1->next;
 }
}
int push(struct node **head_ref,int new_data){
struct node *temp=(struct node *)malloc(sizeof(struct node ));
temp->data=new_data;
temp->next=*head_ref;
*head_ref=temp;
}

int print(struct node *head){
while(head!=NULL){
printf(" %d ",head->data);
head=head->next;
}
}

int main(void){
struct node *head=NULL;
printf("list contaiing dup");
push(&head,3);
push(&head,7);
push(&head,3);
push(&head,3);
push(&head,3);
RemoveDuplicate(head);
print(head);
return  0;
}


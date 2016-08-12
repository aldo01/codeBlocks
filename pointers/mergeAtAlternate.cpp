/*Merge a linked list into another linked list at alternate positions*/

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node{
 int data;
 struct node *next;
};
int push(struct node **,int);
int Merge_alternate(struct node *,struct node **);
int printLIst(struct node *);


 int Merge_alternate(struct node *p, struct node **q)
{
     struct node *p_curr = p, *q_curr = *q;
     struct node *p_next, *q_next;

     // While therre are avialable positions in p
     while (p_curr != NULL && q_curr != NULL)
     {
         // Save next pointers
         p_next = p_curr->next;
         q_next = q_curr->next;

         // Make q_curr as next of p_curr
         q_curr->next = p_next;  // Change next pointer of q_curr
         p_curr->next = q_curr;  // Change next pointer of p_curr

         // Update current pointers for next iteration
         p_curr = p_next;
         q_curr = q_next;
    }

    *q = q_curr; // Update head pointer of second list
}

int push(struct node **head_ref,int new_data){

  struct node *current=(struct node *)malloc(sizeof(struct node));
  current->data=new_data;
  current->next=*head_ref;
  *head_ref=current;

}

int printList(struct node *head){
struct node *temp=head;

while(temp!=NULL){
printf(" %d ",temp->data);
temp=temp->next;
}

}


int main(){
struct node *p=NULL;
struct node *q=NULL;
push(&p,23);
push(&p,12);
push(&p,90);
printf("the first list is..\n");
printList(p);
printf("second list is...\n");
push(&q,44);
push(&q,78);
push(&q,55);
push(&q,34);
push(&q,20);

printList(q);
Merge_alternate(p,&q);
printf("modified first list is ..\n");
printList(p);
printf("modified second list..\n");
printList(q);
getchar();
return(0);
}

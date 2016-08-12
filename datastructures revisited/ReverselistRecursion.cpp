#include<stdio.h>
#include<malloc.h>
 struct node {
 int data;
 struct node *next;
 };

 int ReverseRecursion(struct node **);
 int push(struct node **,int);
 int push(struct node *);

  int ReverseRecursion(struct node **head_ref){
   struct node *first;
   struct node *rest;
   if(*head_ref==NULL)
    return 0;
    first= *head_ref;
    rest=first->next;
    if(rest==NULL)
     return 0;

     ReverseRecursion(&rest);
     first->next->next=first;
     first->next=NULL;
     *head_ref=rest;
  }

 int push(struct node **head,int new_data){
 struct node *temp=(struct node *)malloc(sizeof(struct node ));
 temp->data=new_data;
 temp->next=*head;
 *head=temp;
 }

 int print(struct node *Head){

  struct node *temp;

  if(Head != NULL)
  {
    temp = Head;
    printf("\n");
    do {
      printf("%d ", temp->data);
      temp = temp->next;
    } while(temp != Head);
  }
}

int main(){
     struct node *Head=NULL;
     push(&Head,23);
     push(&Head,12);
     push(&Head,44);
     push(&Head,32);
     push(&Head,91);
     print(Head);
     ReverseRecursion(&Head);
     print(Head);
     }


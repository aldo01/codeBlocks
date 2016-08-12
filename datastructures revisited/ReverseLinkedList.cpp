#include<stdio.h>
#include<malloc.h>
 struct node{
 int data;
 struct node *next1;
 };
 int ReverseList(struct node **);
 int push(struct node **,int);
 int print(struct node *);

 int ReverseList(struct node **head){
  struct node *result=NULL;
  struct node *current=*head;
  struct node *next1;
  while(current!=NULL){
   next1=current->next1;
   result=current->next1;
   current=next1;
  }
  *head=result;
 }

int push(struct node **head,int new_data){
 struct node *temp=(struct node *)malloc(sizeof(struct node ));
 temp->data=new_data;
 temp->next1=*head;
 *head=temp;
}


int main(){
     struct node *Head=NULL;
     push(&Head,23);
     push(&Head,12);
     push(&Head,44);
     push(&Head,32);
     push(&Head,91);
     print(Head);
     ReverseList(&Head);
     print(Head);
     }

      int print(struct node *Head){

  struct node *temp;

  if(Head != NULL)
  {
    temp = Head;
    printf("\n");
    do {
      printf("%d ", temp->data);
      temp = temp->next1;
    } while(temp != Head);
  }
}

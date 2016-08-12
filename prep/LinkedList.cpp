#include<stdio.h>
#include<malloc.h>

struct snode{
 int data;
 struct snode *next;
};

struct qnode{
 struct snode *stack1;
 struct snode *stack2;
};

int push(struct node **head,int new_data){
  struct node *temp=(struct node *)malloc(sizeof(struct node));
  temp->data=new_data;
  temp->next=*head;
  *head=temp;
}

int main(){

  struct qnode *q=(stuct node *)malloc(sizeof(struct node));
  enqueue(q,1);
  enqueue(q,2);
  enqueue(q,3);

  print
}

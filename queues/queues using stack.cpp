#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

  struct snode{
  int data;
  struct snode *next;
 };

 struct queue{
    struct snode *stack1;
    struct snode *stack2;

 };
 int push(struct snode **,int);
 int pop(struct snode **);
 int enqueue(struct queue *,int);
 int dequeue(struct queue *);

  int main(){

   struct queue *q=(struct queue *)malloc(sizeof(struct queue));
   q->stack1=NULL;
   q->stack2=NULL;

   enqueue(q,1);
   enqueue(q,2);
   enqueue(q,4);
  // enqueue(q,5);

   printf("%d ",dequeue(q));
   printf("%d ",dequeue(q));
   printf("%d ",dequeue(q));
   getchar();

  }
 int enqueue(struct queue *q,int x){
   push(&q->stack1,x);

 }
 int dequeue(struct queue *q){
 int x;


   if(q->stack1==NULL&&q->stack2==NULL)
   {
     printf("queue is empty");
     getchar();
      exit(0);
     if(q->stack2==NULL){
       while(q->stack1!=NULL){
         x=pop(&q->stack1);
         push(&q->stack2,x);
       }
     }
     x=pop(&q->stack2);
     return x;

   }
 }

 int pop(struct snode **top_ref){
   int res;
   struct snode *top;
   if(*top_ref==NULL){
     printf("stack overflow");
      getchar();
      exit(0);
   }
   else{
     top=*top_ref;
       res=top->data;
       *top_ref=top->next;
       free(top);
       return res;
   }
 }

 int push(struct snode **top_ref,int new_data){
    struct snode *top=(struct snode *)malloc(sizeof(struct snode ));
    if(top==NULL){
     printf("stack overflow");
     getchar();
     return 0;
    }
    top->data=new_data;
    top->next=*top_ref;
    *top_ref=top;
 }

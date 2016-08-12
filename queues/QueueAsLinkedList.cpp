#include<stdio.h>
#include<malloc.h>

struct Qnode{
int data;
struct Qnode *next;
};

struct queue{
  struct Qnode *rear,*front;
};

 struct queue *create();
 struct Qnode *dequeue(struct queue *);
 int enqueue(struct Qnode *,int);
 struct Qnode *newNode(int);


struct Qnode *newNode(int data){
 struct Qnode *temp=(struct Qnode *)malloc(sizeof(struct Qnode));
 temp->data=data;
 temp->next=NULL;
 return (temp);

}
 struct queue *create(){
     struct queue *q=(struct queue*)malloc(sizeof(struct queue));
     q->front=NULL;
     q->rear=NULL;
     return(q);
 }

 int enqueue(struct queue *q,int k){
    struct Qnode *temp=newNode(k);
     if(q->rear==NULL){
       q->front=q->rear=temp;

       return 0;
     }

      q->rear->next=temp;
        q->rear=temp;
 }
 struct Qnode *dequeue(struct queue *q){
   if(q->front==NULL)
     return NULL;
     struct Qnode *temp=q->front;
     q->front=q->front->next;
     // if the front is empty..
     if(q->front==NULL)
       q->rear=NULL;

       return(temp);

 }

 int main(void){
    struct queue *q=create();
     enqueue(q,12);
     enqueue(q,23);
     enqueue(q,55);
    // dequeue(q);
     struct Qnode *n=dequeue(q);
     printf("%d",n->data);

     return 0;


 }

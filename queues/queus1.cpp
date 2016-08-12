#include<stdio.h>
#include<ctype.h>
#define MAX 20
struct queue
{
    int rear,front;
    int data[MAX];
};
int print(struct queue *);
int init(struct queue *);
int enqueue(struct queue *,int);
int full(struct queue *);
int isempty(struct queue *);

int main(void)
{
    struct queue q;
    int x,i,n;
    init(&q);
    printf("enter nos of elements");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&x);
        if(!full(&q))
        {
            enqueue(&q,x);
        }
        else
        {
            printf("queue is full");
        }
    }
    print(&q);

}
int init(struct queue *p)
{
    p->rear==-1;
    p->front==-1;
}
int enqueue(struct queue *p,int x)
{
    if(p->rear==-1)
    {
        p->front=p->rear=0;
        p->data[p->rear]=x;
    }
    else
        p->rear=p->rear+1;
    p->data[p->rear]=x;
}
int print(struct queue *p)
{
    while(!isempty(p))
    {

        printf("%d",p->data);
    }
}
int isempty(struct queue *p)
{
    if(p->rear==-1)
        return (1);
    return(0);
}
int full(struct queue *p)
{
    if(p->rear==MAX-1)
        return(1);
    return(0);
}

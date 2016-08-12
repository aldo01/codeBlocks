#include<stdio.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *next;


};
struct node *mergeSort(struct node *,struct node *);
int push(struct node **,int );
int print(struct node *);

int main()
{
    struct node *a=NULL;

    struct node *b=NULL;
    struct node *res=NULL;

    push(&a,9);
    push(&a,5);
    push(&a,2);
    printf("the first list is");
    print(a);
    push(&b,19);
    push(&b,10);
    push(&b,7);
    printf("the second list is ..");
    print(b);

    res= mergeSort(a,b);
    printf("sorted list is");
    print(res);

}

int push(struct node **head,int new_data)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node ));

    temp->data=new_data;
    temp->next=*head;
    *head=temp;
}

struct node * mergeSort(struct node *a,struct node *b)
{
    struct node *result=NULL;

    if(a==NULL)
        return b;
    if(b==NULL)
        return a;

    if(a->data <= b->data)
    {
        result=a;
        result->next=mergeSort(a->next,b);
    }
    else
    {
        result=b;
        result->next=mergeSort(a,b->next);
    }
    return(result);
}

int print(struct node *res1)
{
    while(res1!=NULL)
    {
        printf(" %d ",res1->data);
        res1=res1->next;
    }

}

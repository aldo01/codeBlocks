#include<stdio.h>
#include<malloc.h>

struct node{
 int data;
 struct node *next;
};

int push(struct node **,int);
int printList(struct node *);
struct node *merge_sort(struct node *,struct node *);

struct node *merge_sort(struct node *a,struct node *b){
 struct node *result=NULL;

 if(a==NULL)
    return b;

 if(b==NULL)
    return a;

 if(a->data < b->data){
    result=a;
  result->next=merge_sort(a->next,b);
 }
  else{
    result=b;
    result->next=merge_sort(a,b->next);

  }
  return result;
}

int main(){

 struct node *a=NULL;
 struct node *b=NULL;
 struct node  *result;
 push(&a,33);
 push(&a,22);
 push(&a,11);

 push(&b,6);
 push(&b,5);
 push(&b,4);

 result=merge_sort(a,b);

 printList(result);

 return 0;

}

int printList(struct node *result){
while(result!=NULL){

    printf(" %d ",result->data);
    result=result->next;
}

}

int push(struct node **head,int new_data){
 struct node* temp=(struct node *)malloc(sizeof(struct node));
 temp->data=new_data;
 temp->next=*head;
 *head=temp;
}

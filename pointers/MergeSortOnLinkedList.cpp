#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

 struct node{
 int data;
 struct node *next;

 };
 int push(struct node **,int);
 struct node *SortedMerge(struct node *,struct node *);
 int mergeSort(struct node **);
 int FrontBackSplit(struct node *,struct node **,struct node **);
 int printList(struct node *);

 int main(void){
   struct node *Head=NULL;
   push(&Head,23);
   push(&Head,2);
   push(&Head,90);
   push(&Head,12);
   printList(Head);
   printf("\n");
   mergeSort(&Head);
   printList(Head);
   return 0;

 }
 int mergeSort(struct node **head_ref){
 struct node *head=*head_ref;
 struct node *a,*b;
 //base case:
 if(head==NULL || head->next==NULL){
   return 0;
 }
  FrontBackSplit(head,&a,&b);
  mergeSort(&a);
  mergeSort(&b);
  *head_ref=SortedMerge(a,b);
 }

  int FrontBackSplit(struct node *source,struct node **front,struct node **back){
  struct node *fast,*slow;
  if(source==NULL || source->next==NULL){
   *front=source;
   *back=NULL;
  }
  else{
    slow=source;
    fast=source->next;


  while(fast!=NULL){
  fast=fast->next;
  if(fast!=NULL){
   slow=slow->next;
   fast=fast->next;

  }
}
 *front=source;
 *back=slow->next;
 slow->next=NULL;

}
}
struct node *SortedMerge(struct node *a,struct node *b){
struct node *result=NULL;
if(a==NULL){
result=b;
return(result);
}
if(b==NULL){
result=a;
return(result);
}
 if(a->data<=b->data){
 result=a;
 result->next=SortedMerge(a->next,b);

 }
 else{
  result=b;
  result->next=SortedMerge(a,b->next);

 }

  return(result);
}

int push(struct node **head_ref,int new_data){
struct node *temp=(struct node *)malloc(sizeof(struct node *));
temp->data=new_data;
temp->next=*head_ref;
*head_ref=temp;

}
int printList(struct node *node){
  while(node!=NULL){
  printf(" %d ",node->data);
  node=node->next;
  }
}

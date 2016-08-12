#include<stdio.h>
#include<malloc.h>

 struct node{
  int data;
  struct node *next;
 };

 struct node *QuickSort(struct node **head){
    *head=QuickSortRec(*head,getTail(*head));
    return  0;
 }

 struct node *QuickSortRec(struct node **head,struct node *end){
   if(!head && head==end)
    return head;

  struct node *newHead=NULL;
  struct node *newend=NULL;
  struct node *pivot=partition(head,end,&newHead,&newend);
   if(newHead!=pivot){
    struct node *tmp=newHead;
    while(tmp!=pivot){
     temp
    }
   }
 }

 int push(struct node **head,int new_data){
  struct node *temp=(struct node *)malloc(sizeof(struct node));
  temp->data=new_data;
  temp->next=*head;
  *head=temp;
 }

 struct node *getTail(struct node *curr){
  while(curr!=NULL && curr->next!=NULL){
   curr=curr->next;
  }
   return curr;
 }

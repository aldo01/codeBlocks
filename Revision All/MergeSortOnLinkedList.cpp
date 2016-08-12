#include<stdio.h>
#include<malloc.h>

 struct node{
 int data;
 struct node *next;
};

 int frontBackSplit(struct node *,struct node **,struct node **);
 int print(struct node *);
 struct node *SortedMerge(struct node *,struct node *);
 int MergeSort(struct node **);


int push(struct node **head,int new_data){
  struct node *temp=(struct node *)malloc(sizeof(struct node));
  temp->data=new_data;
  temp->next=*head;
  *head=temp;
}
 int MergeSort(struct node **head){
  struct node *head_ref=*head;
  struct node *a;
  struct node *b;

  if(head_ref!=NULL || head_ref->next!=NULL){
   return 0;
  }
   frontBackSplit(head_ref,&a,&b);
   MergeSort(&a);
   MergeSort(&b);
   *head_ref = SortedMerge(a,b);
 }

  int frontBackSplit(struct node *source,struct node **frontref,struct node **backref){
   struct node *slow;
   struct node *fast;

   if(source==NULL && source->next==NULL){
    *frontref=source;
    *backref=NULL;
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
      *frontref=source;
      *backref=slow->next;
      slow->next=NULL;

   }

  }

 struct node *SortedMerge(struct node *a, struct node *b){
  struct node *result=NULL;
  if(a==NULL)
   return b;
   if (b==NULL)
    return a;

   if(a->data < b->data){
    result=a;
    result->next=SortedMerge(a->next,b);
   }
    else{
     result=b;
     result->next=SortedMerge(a,b->next);
    }
    return result;
 }

 int print(struct node *head){
  struct node *temp=head;
  while(temp!=NULL){
   printf("%d\n",temp->data);
   temp=temp->next;
  }
 }

  int main(){

   struct node *head=NULL;
   push(&head,45);
   push(&head,3);
   push(&head,23);
   push(&head,6);
   push(&head,12);

   MergeSort(&head);
   print(head);
   return 0;
  }


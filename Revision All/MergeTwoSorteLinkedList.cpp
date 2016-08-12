#include<stdio.h>
#include<malloc.h>

struct node{
 int data;
 struct node *next;
};

 int push(struct node **,int);
 int print(struct node *);

struct node *SortedMerge(struct node *a, struct node *b){
 struct node *result=NULL;
 if(a==NULL){
  return b;
  }
  if(b==NULL){
   return a;
  }
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

int main(){
  struct node *res=NULL;
  struct node *a=NULL;
  struct node *b=NULL;
  push(&a, 15);
  push(&a, 10);
  push(&a, 5);

  push(&b, 20);
  push(&b, 3);
  push(&b, 2);

  printf("first list :\n");
  print(a);
  printf("second list :\n");
  print(b);
  res=SortedMerge(a,b);
  printf("sorted List :\n ");
  print(res);
  return 0;
}

int push(struct node **head,int new_data){
  struct node *temp=(struct node *)malloc(sizeof(struct node ));
  temp->data=new_data;
  temp->next=*head;
  *head=temp;
}
int print(struct node *head){
 while(head!=NULL){
  printf("%d\n",head->data);
  head=head->next;
 }
}

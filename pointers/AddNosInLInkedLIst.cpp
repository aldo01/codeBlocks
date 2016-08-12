#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<ctype.h>

struct node{
int data;
struct node *next;
};


int push(struct node **,int);
int printList(struct node *);
int getSize(struct node *);
int swap(struct node **,struct node **);
struct node *addSameSize(struct node *,struct node *,int *);
int addCarryToRemaining(struct node *,struct node *,int *,struct node **);
int addList(struct node *,struct node *,struct node **);


int main(void){
struct node *head1=NULL,*head2=NULL,*result;
int arr1[]={4,5,6};
int arr2[]={1,2,3};
int size1=sizeof(arr1)/sizeof(arr1[0]);
int size2=sizeof(arr2)/sizeof(arr2[0]);
  int i=0;
  for(i=size1-1;i<=0;--i){
  push(&head1,arr1[i]);
  }
  for(i=size2-1;i<=0;--i){
  push(&head2,arr2[i]);
  }

  addList(head1,head2,&result);
  printList(result);
}
int addList(struct node *head1,struct node *head2,struct node **result){
 struct node *cur;
 if(head1==NULL){
 *result=head2;
 return 0;
 }
 if(head2==NULL){
  *result=head1;
  return 0;
 }
 int size1=getSize(head1);
 int size2=getSize(head2);
   int carry=0;
  if(size1==size2){
  *result=addSameSize(head1,head2,&carry);
  }
  else{

   int diff=abs(size1-size2);
    if(size1<size2){
    swap(&head1,&head2);
    }
    for(cur=head1;diff--;cur=cur->next)

       *result=addSameSize(cur,head2,&carry);
       addCarryToRemaining(head1,cur,&carry,result);
  }

   if(carry){
     push(result,carry);
   }
}
 struct node * addSameSize(struct node *head1,struct node *head2,int *carry){
   int sum;
   if(head1==NULL)
   return 0;
//   int sum;
   struct node *result=(struct node *)malloc(sizeof(struct node ));
   result->next=addSameSize(head1->next,head2->next,carry);
   sum=head1->data+head2->data+*carry;
   *carry=sum/10;
   sum=sum%10;
   result->data=sum;
   return result;


 }
 int addCarryToRemaining(struct node *head1,struct node *cur,int *carry,struct node **result){
   int sum;
   if(head1!=cur){
   addCarryToRemaining(head1->next,cur,carry,result);
   sum=head1->data+*carry;
   *carry=sum/10;
   sum=sum%10;
   push(result,sum);

   }
 }



int push(struct node **head_ref,int new_data){
struct node *temp=(struct node *)malloc(sizeof(struct node *));
temp->data=new_data;
temp->next=*head_ref;
*head_ref=temp;

}
int printList(struct node *head){
while(head!=NULL){
printf(" %d ",head->data);
head=head->next;
}
}

int getSize(struct node *node){
 int size=0;
 while(node!=NULL){
  node=node->next;
  size++;
 }
  return size;
}

int swap(struct node **a,struct node **b){
 struct node *temp=*a;
   *a=*b;
   *b=temp;

}

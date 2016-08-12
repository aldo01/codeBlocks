#include<stdio.h>
#include<malloc.h>

struct node{
int data;
struct node *next;
};

bool isSumFind(struct node *headA,struct node *headB,struct node *headC,int givenNos){
struct node *a=headA;

while(a!=NULL){
struct node *b=headB;
struct node *c=headC;

while(b!=NULL && c!=NULL){
 int sum=a->data+b->data+c->data;
 if(sum==givenNos){
 printf("triplet found..%d %d %d",a->data,b->data,c->data);
 return true;
 }
else if(sum<givenNos)
  b=b->next;
  else
   c=c->next;
}
a=a->next;

}
  printf("no such triplet");
  return false;
}

int push(struct node **head_ref,int new_data){
struct node *temp=(struct node *)malloc(sizeof(struct node ));
temp->data=new_data;
temp->next=*head_ref;
*head_ref=temp;


}
int main(void){
struct node *headA=NULL;
struct node *headB=NULL;
struct node *headC=NULL;
push(&headA,20);
push(&headA,12);
push(&headA,8);
push(&headA,2);

push(&headB,33);
push(&headB,23);
push(&headB,15);

push(&headC,4);
push(&headC,13);
push(&headC,20);
push(&headC,34);

isSumFind(headA,headB,headC,39);
return 0;


}

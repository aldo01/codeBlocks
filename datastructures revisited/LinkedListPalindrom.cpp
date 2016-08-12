#include<stdio.h>
#include<malloc.h>
struct node {
 struct node *next;
 char data;
};
//........................................
bool isPalindrom(struct node *);
int printList(struct node *);
bool compareList(struct node *,struct node *);
int reverseList(struct node **);
//.......................................

bool isPalindrom(struct node *head){
  struct node *slow_ptr=head,*fast_ptr=head;
  struct node *second_half,*pre_slow_ptr=head;
  struct node *midnode=NULL;
  bool res=true;
  if(head!=NULL && head->next!=NULL){
    while(fast_ptr!=NULL && fast_ptr->next!=NULL){
     fast_ptr=fast_ptr->next->next;
     pre_slow_ptr=slow_ptr;
     slow_ptr=slow_ptr->next;
    }
    if(fast_ptr!=NULL){
     midnode=slow_ptr;
     slow_ptr=slow_ptr->next;
    }
    second_half=slow_ptr;
    pre_slow_ptr->next=NULL;
    reverseList(&second_half);
    res=compareList(head,second_half);
    if(midnode!=NULL){
     pre_slow_ptr->next=midnode;
     midnode->next=second_half;
    }
    else
    pre_slow_ptr->next=second_half;
  }
  return res;
 }

int push(struct node **head_ref,int new_data){
 struct node *temp=(struct node *)malloc(sizeof(struct node ));
 temp->data=new_data;
 temp->next=*head_ref;
 *head_ref=temp;
}
 bool compareList(struct node *head1,struct node *head2){
  struct node *temp1=head1;
  struct node *temp2=head2;
  while(temp1 && temp2){
   if(temp1->data==temp2->data){
   temp1=temp1->next;
   temp2=temp2->next;
   }
   else return 0;
  }
  if(temp1==NULL && temp2==NULL)
  return 1;
  return 0;
 }

 int reverseList(struct node **head_ref){
  struct node *current;
  struct node *result=NULL;
  struct node *next;
  while(current!=NULL){
   next=current->next;
   result=current->next;
   current=next;
  }
  *head_ref=result;
 }

int printList(struct node *head){
 while(head!=NULL){
 printf("%d",head->data);
 head=head->next;
 }
}
int main(){
struct node *head=NULL;
char str[] = "abacaba";
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
       push(&head, str[i]);
       printList(head);
       isPalindrom(head)? printf("Is Palindrome\n\n"):
                           printf("Not Palindrome\n\n");
    }

    return 0;
}

#include<stdio.h>
#include<malloc.h>


 struct node {
  int data;
  struct node*next;

 };
 int push(struct node **,int );
 int print(struct node*);
  int split(struct node *,struct node **,struct node **);

  int main(){
    struct node *head=NULL;
    struct node *head1=NULL;
    struct node *head2=NULL;


      push(&head,23);
      push(&head,32);
      push(&head,91);
      push(&head,55);
      push(&head,77);
      split(head,&head1,&head2);
       print(head);
       print(head1);
       print(head2);

    getchar();
    return 0;
  }


    int push(struct node **head_ref, int data)
{
  struct node *ptr1 = (struct node *)malloc(sizeof(struct node));
  struct node *temp = *head_ref;
  ptr1->data = data;
  ptr1->next = *head_ref;

  /* If linked list is not NULL then set the next of
    last node */
  if(*head_ref != NULL)
  {
    while(temp->next != *head_ref)
      temp = temp->next;
    temp->next = ptr1;
  }
  else
     ptr1->next = ptr1; /*For the first node */

  *head_ref = ptr1;
}

     int print(struct node *head)
{
  struct node *temp = head;
  if(head != NULL)
  {
    printf("\n");
    do {
      printf("%d ", temp->data);
      temp = temp->next;
    } while(temp != head);
  }
}


 int split(struct node *head, struct node **head1_ref,
                                            struct node **head2_ref)
{
  struct node *slow_ptr = head;
  struct node *fast_ptr = head;

  if(head == NULL)
    return 0;

  /* If there are odd nodes in the circular list then
     fast_ptr->next becomes head and for even nodes
     fast_ptr->next->next becomes head */
  while(fast_ptr->next != head &&
         fast_ptr->next->next != head)
  {
     fast_ptr = fast_ptr->next->next;
     slow_ptr = slow_ptr->next;
  }

 /* If there are even elements in list then move fast_ptr */
  if(fast_ptr->next->next == head)
    fast_ptr = fast_ptr->next;

  /* Set the head pointer of first half */
  *head1_ref = head;

  /* Set the head pointer of second half */
  if(head->next != head)
    *head2_ref = slow_ptr->next;

  /* Make second half circular */
  fast_ptr->next = slow_ptr->next;

  /* Make first half circular */
  slow_ptr->next = head;
}

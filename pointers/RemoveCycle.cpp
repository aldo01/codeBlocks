#include<stdio.h>
#include<malloc.h>

struct node{
int data;
struct node *next;
};
int removeCycle(struct node *,struct node *);
int DetectAndRemove(struct node *);
int DetectAndRemove(struct node *head){

  struct node *fast=head,*slow=head;
  while(slow && fast &&fast->next){
  slow=slow->next;
  fast=fast->next->next;

   if(slow==fast){
    removeCycle(slow,head);
     return 1;

   }

  }
    return 0;

  }
   int removeCycle(struct node *slow,struct node *head){
    struct node *ptr1;
    struct node *ptr2;
    ptr1=head;
    while(1){
     ptr2=slow;
     while(ptr2->next!=slow && ptr2->next!=ptr1){
     ptr2=ptr2->next;
     }
     if(ptr2->next==ptr1)
      break;

      else
        ptr1=ptr1->next;
    }
  ptr2->next=NULL;
   }

int push(struct node **head_ref,int new_data){
struct node *temp=(struct node *)malloc(sizeof(struct node ));
temp->data=new_data;
temp->next=*head_ref;
*head_ref=temp;

}
int printList(struct node *node)
{
    while(node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
}
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;

    push(&head, 10);
    push(&head, 4);
    push(&head, 15);
    push(&head, 20);
    push(&head, 50);

    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;

    DetectAndRemove(head);

    printf("Linked List after removing loop \n");
    printList(head);

    //getchar();
    return 0;
    }

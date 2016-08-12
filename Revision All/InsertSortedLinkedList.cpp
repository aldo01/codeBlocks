#include<stdio.h>
#include<malloc.h>

struct node{
 int data;
 struct node *next;
};

 int sortedInsert(struct node **head_ref,struct node *new_node){
  struct node *current;
  if(*head_ref==NULL || (*head_ref)->data > new_node->data){
   new_node->next=*head_ref;
   *head_ref=new_node;
  }
  else{
   current=*head_ref;
   while(current->next!=NULL && current->next->data < new_node->data){
    current=current->next;
   }
   new_node->next = current->next;
        current->next = new_node;
  }
 }
 struct node *newNode(int new_data){
  struct node *new_node=(struct node *)malloc(sizeof(struct node ));
  new_node->data=new_data;
  new_node->next=NULL;
  return new_node;
 }

 /* Function to print linked list */
void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

/* Drier program to test count function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
    struct node *new_node = newNode(5);
    sortedInsert(&head, new_node);
    new_node = newNode(10);
    sortedInsert(&head, new_node);
    new_node = newNode(7);
    sortedInsert(&head, new_node);
    new_node = newNode(3);
    sortedInsert(&head, new_node);
    new_node = newNode(1);
    sortedInsert(&head, new_node);
    new_node = newNode(9);
    sortedInsert(&head, new_node);
    printf("\n Created Linked List\n");
    printList(head);

    getchar();
    return 0;
}

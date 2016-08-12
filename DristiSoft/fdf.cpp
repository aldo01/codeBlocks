#include<stdio.h>
#include<stdlib.h>
#include<math.h>


struct node
{
    int data;
    struct node* next;
};

struct node *reverse (struct node *head, int k)
{
    struct node* current = head;
    struct node* next = NULL;
    struct node* prev = NULL;
    int count = 0;

    /*reverse first k nodes of the linked list */
    while (current!= NULL && count < k)
    {
       next  = current->next;
       current->next = prev;
       prev = current;
       current = next;
       count++;
    }

    /* next is now a pointer to (k+1)th node
       Recursively call for the list starting from current.
       And make rest of the list as next of first node */
    if(next !=  NULL)
    {  head->next = reverse(next, k); }

    /* prev is new head of the input list */
    return prev;
}


void insert(struct node** tail_ref, int new_data)
{
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));


    new_node->data  = new_data;

    new_node->next = (*tail_ref);
    (*tail_ref)    = new_node;
}


void printList(struct node *node)
{

	printf("%d ", node->data);

    while(node->next != NULL)
    {
	node = node->next;
        printf("->%d", node->data);
    }
	printf("\n");
}


int main(void)
{

   // struct node* head = (struct node*) malloc(sizeof(struct node));
   struct node *head;
    int i=0;
    int M;
    int K;

	scanf("%d", &M);
	scanf("%d", &K);


	int p;
	//scanf("%d", &p);
    	//head->data = p;
        //head->next = NULL;
        struct node* tail = head;
    for(i=0;i<M-1;i++){
	scanf("%d", &p);
    	insert(&tail, p);
    }

     head = reverse(head, K);


     printList(head);

     return(0);
}


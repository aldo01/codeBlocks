#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<malloc.h>


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

    while(current!=NULL && count<k){
    	 next=current->next;
    	 current->next=prev;
    	 prev=current;
    	 current=next;
    	 count++;
    }
    if(next!=NULL){
    	head->next=reverse(next,k);
        return prev;
    }
   /* count=0;
    while(count<k-1 && current!=NULL){

    	head->next=current;
    	count++;
    }

    if(next!=NULL){
      head->next=reverse(next,k);
    		return current;
    	}

   //return current;*/
}

void insert(struct node** tail_ref, int new_data)
{
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));


    new_node->data  = new_data;

    new_node->next=(*tail_ref);
     (*tail_ref)=new_node;
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

    struct node* head = (struct node*) malloc(sizeof(struct node));
    int i=0;
    int M;
    int K;

	scanf("%d", &M);
	scanf("%d", &K);


	int p;
	scanf("%d", &p);
    	head->data = p;
        head->next = NULL;
        struct node* tail = head;
    for(i=M;i>0;i--){
	scanf("%d", &p);
    	insert(&tail, p);
    }

     head = reverse(head, K);


     printList(head);

     return(0);
}


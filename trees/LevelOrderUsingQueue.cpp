#include<stdio.h>
#include<malloc.h>
#define MAX_Q 500
struct node{
int data;
struct node *left;
struct node *right;
};
// function declarations,,.................................................................

struct node **createQ(int *,int *);
 struct node *new_node(int);
 int enqueue(struct node **,int *,struct node *);
 struct node * dequeue(struct node **,int *);

 //..........................................................................................

 struct node **createQ(int *front,int *rear){
  struct node **queue=(struct node **)malloc(sizeof(struct node *)*MAX_Q);
  *rear=*front=0;
  return queue;
 }
//..............................................................................................

  int PrintLevelOrder(struct node *root){
   int front,rear;
   struct node **queue=createQ(&front,&rear);
     struct node *temp=root;
     while(temp){
       printf(" %d ",temp->data);
       // enqueue the item
       enqueue(queue,&rear,temp->left);
       //enqueue the right..

       enqueue(queue,&rear,temp->right);

       // dequeue  ...
       temp=dequeue(queue,&front);
     }

  }

    struct node **createQ(int *front,int *rear){
      struct node **queue=(struct node **)malloc(sizof(struct node *)MAX_Q);
      *front=*rear=0;
      return queue;
    }
  int enqueue(struct node **queue,int *rear,struct node *newNode){
     queue[*rear]=newNode;
     (*rear)++;

  }

  struct node * dequeue(struct node **queue,int *front){
    (*front)++;
    return queue[*front-1];
  }
struct node *new_node(int new_data){
  struct node *node=(struct node *)malloc(sizeof(struct node ));
  node ->data=new_data;
  node ->left=NULL;
  node ->right=NULL;
  return node;
}

int main(void){
  struct node *root=new_node(12);
  root->left=new_node(23);
  root->right=new_node(44);
  root->left->right=new_node(21);
  root->right->left=new_node(90);

  PrintLevelOrder(root);
  return 0;
}

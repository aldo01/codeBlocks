#include<stdio.h>
#include<malloc.h>

struct node{
int data;
struct node *left;
struct node *right;
};
 struct node *newNode(int);
int mirror(struct node *);
int inOrder(struct node *);

struct node *newNode(int data){
 struct node *node=(struct node *)malloc(sizeof(struct node ));
 node->data=data;
 node->left=NULL;
 node->right=NULL;
 return node;
}

int mirror(struct node *node){
if(node==NULL)
 return 0;
 else{
   struct node *temp;


  temp=node->left;
  node->left=node->right;
  node->right=temp;
  mirror(node->left);
 mirror(node->right);
 }
 }

 int main(void){
  struct node *root = newNode(5);
  root->left        = newNode(4);
  root->right       = newNode(3);
  root->left->left  = newNode(2);
  root->left->right = newNode(1);

  /* Print inorder traversal of the input tree */
  printf("\n Inorder traversal of the constructed tree is \n");
  inOrder(root);

  /* Convert tree to its mirror */
  mirror(root);

  /* Print inorder traversal of the mirror tree */
  printf("\n Inorder traversal of the mirror tree is \n");
  inOrder(root);

  getchar();
  return 0;

 }

int inOrder(struct node *node){
if(node==NULL)
 return 0;
 inOrder(node->left);
 printf(" %d ",node->data);
 inOrder(node->right);
}

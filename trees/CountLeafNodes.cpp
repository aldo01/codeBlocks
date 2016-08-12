#include<stdio.h>
#include<malloc.h>
int count=0;
  struct node{
   int data;
   struct node *left;
   struct node *right;
  };

  int countLeaf(struct node *);
  struct node *newNode(int);

  int countLeaf(struct node *root){
 // int count =0;


   if(root->left==NULL && root->right==NULL){
     count++;

   }
   else{
       countLeaf(root->left);
       countLeaf(root->right);
   }
   return count;
  }

  struct node *newNode(int data){
    struct node *node=(struct node *)malloc(sizeof(struct node));
    node->data=data;
    node->left=node->right=NULL;
    return node;
  }

  int main(void){
   struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  printf("nos of leaf nodes are %d",countLeaf(root));
  }

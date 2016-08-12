#include<stdio.h>
#include<malloc.h>

 struct node{
   int data;
   struct node *left;
   struct node *right;
 };

int isBST(struct node *root){
   if(root==NULL)
    return 1;
    if(root->left!=NULL && root->left->data > root->data)
      return 0;
      if(root->right!=NULL && root->right->data < root->data)
        return 0;

        if(!isBST(root->left) || !isBST(root->right))
          return 0;

          return 1;
 }

 struct node *newNode(int data){
   struct node *node=(struct node *)malloc(sizeof(struct node ));
   node->data=data;
   node->right=NULL;
   node->left=NULL;
   return node;
 }

 int main(void){
   struct node *root=newNode(20);
   root->left=newNode(15);
   root->right=newNode(22);
   root->left->left=newNode(12);
   root->left->right=newNode(21);
  printf("%d",isBST(root));
   return 0;
 }

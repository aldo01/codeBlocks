#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<ctype.h>
  struct node {
   int data;
   struct node *left;
   struct node *right;

  };
 //............................................................
 int height(struct node *);
 int max(int,int);
 bool isBalanced(struct node *);


 //..............................................................
  struct node *newNode(int data){
   struct node *temp=(struct node *)malloc(sizeof(struct node ));
   temp->data=data;
   temp->left=NULL;
   temp->right=NULL;
   return temp;

  }

  bool isBalanced(struct node *node){
     if(node==NULL)
      return 1;
      int lh=height(node->left);
      int rh=height(node->right);

      if(abs(lh-rh)<=1 && isBalanced(node->left) && isBalanced(node->right))
      return 1;

      return 0;


  }


int height(struct node *node){
 if(node==NULL)
   return 0;
   return 1+max(height(node->left),height(node->right));
}

 int max(int a, int b){
   return (a>=b)?a:b;
 }

  int main(void){
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);

    if(isBalanced(root))
      printf("Tree is balanced");
    else
      printf("Tree is not balanced");

    getchar();
    return 0;
  }

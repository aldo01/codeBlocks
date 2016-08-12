#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

 struct node{
  int data;
  struct node *left;
  struct node *right;
 };
 //..........................................................
 int incrementNode(struct node *,int);
 struct node *newNode(int);
 int convertTree(struct node *);
 int printInorder(struct node *);
//.............................................................

 int convertTree(struct node *root){
  int left_data=0,right_data=0;
  int diff;
  if(root==NULL &&(root->left==NULL && root->right==NULL))
   return 0;
   else{
    convertTree(root->left);
    convertTree(root->right);

     if(root->left!=NULL)
       left_data=root->left->data;

    if(root->right!=NULL)
       right_data=root->right->data;
        diff=right_data+left_data-root->data;

     if(diff>0)
      root->data=root->data+diff;

     if(diff<0)
     incrementNode(root,-diff); //  THAT IS TRICKY PART OF THE PROBLEM "- DIFF IS TO MAKE VALUE POSITIVE"
   }
 }

  int incrementNode(struct node *node,int diff){

   if(node->left!=NULL){
     node->left->data=node->left->data+diff;
     incrementNode(node->left,diff);
   }
   else if(node->right!=NULL){
    node->right->data=node->right->data+diff;
    incrementNode(node->right,diff);
   }
  }

   struct node *newNode(int data){
    struct node *temp=(struct node *)malloc(sizeof(struct node ));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
   }

   int main(void){

    struct node *root = newNode(50);
  root->left        = newNode(7);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left  = newNode(1);
  root->right->right = newNode(30);

  printf("\n Inorder traversal before conversion ");
  printInorder(root);

  convertTree(root);

  printf("\n Inorder traversal after conversion ");
  printInorder(root);

  //getchar();
  return 0;
   }

   int printInorder(struct node *node){
    if(node==NULL)
     return 0;
      printInorder(node->left);
      printf("%d",node->data);
      printInorder(node->right);
   }

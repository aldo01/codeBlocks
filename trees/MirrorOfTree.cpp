#include<stdio.h>
#include<malloc.h>

  struct node{
  int data;
  struct node*left;
  struct node *right;
  };

  struct node *newNode(int data){
   struct node *node=(struct node *)malloc(sizeof(struct node ));
   node->data=data;
   node->left=NULL;
   node->right=NULL;
  }

int mirror(struct node* node){
  if(node==NULL)
    return 0;
    else{
     struct node *temp;

     temp=node->left;
     node->left=node->right;
     node->left=temp;
     mirror(node->left);
     mirror(node->right);
    }
}

 int inorder(struct node *node){
 if(node==NULL)
    return 0;
    printf(" %d ",node->data);
    inorder(node->left);
   // printf(" %d ",node->data);
    inorder(node->right);
 }

 int main(void){
 struct node *root;
 root=newNode(20);
root->left=newNode(8);
root->right=newNode(22);
root->left->left=newNode(4);
root->left->right=newNode(12);
root->left->right->left=newNode(10);
root->left->right->right=newNode(14);
 printf("the tree constructed\n");
 inorder(root);
 printf("\nthe mirror tree\n");
  mirror(root);
  inorder(root);
  return 0;


  }

#include<stdio.h>
#include<malloc.h>


  struct node {
  int data;
  struct node *left;
  struct node *right;
  };

   int deleteNode(struct node *);
   struct node *newNode(int);
   int printNode(struct node *);

  struct node *newNode(int data){

   struct node *temp=(struct node *)malloc(sizeof(struct node ));
      temp->data=data;
      temp->right=NULL;
      temp->left=NULL;
     return(temp);
  }

  int deleteNode(struct node *node){
    if(node==NULL)
      return 0;
      deleteNode(node->left);
      deleteNode(node->right);
      printf("deleting node : %d",node->data);
      free(node);
  }
  int main(void){

     struct node *root = NULL;
     root=newNode(1);
    root->left            = newNode(2);
    root->right          = newNode(3);
    root->left->left     = newNode(4);
    root->left->right   = newNode(5);

    delete(root);
    //root = NULL;

    printf("\n Tree deleted ");
    printNode(root);

    getchar();
    return 0;
  }

int printNode(struct node *root){
  if(root==NULL)
   //printf("nothing to print");
     printf("root is %d",root->data);
}

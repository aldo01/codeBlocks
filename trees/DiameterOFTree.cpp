#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

 struct node {
  int data;
  struct node *right;
  struct node *left;
 };

 int max(int,int);
 int height(struct node *);
 struct node *newNode(int );


   struct node *newNode(int data){
     struct node *temp=(struct node *)malloc(sizeof(struct node ));
     temp->data=data;
     temp->left=NULL;
     temp->right=NULL;
     return temp;

   }

  int height(struct node *root){
    if(root==NULL)
      return 0;
      else
        return 1+max(height(root->left),height(root->right));
  }


   int diameter(struct node *node){

     if(node==NULL)
       return 0;
     int lheight=height(node->left);
     int rheight=height(node->right);

      int ldiameter=diameter(node->left);
      int rdiameter=diameter(node->right);

      return max(lheight+rheight+1, max(ldiameter,rdiameter));

   }

    int max(int a,int b){
      return(a>=b)?a:b;
    }

    int main()
{

  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
  */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);

  printf("Diameter of the given binary tree is %d\n", diameter(root));

  getchar();
  return 0;
}

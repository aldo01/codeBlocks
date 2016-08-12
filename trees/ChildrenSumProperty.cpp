#include<stdio.h>
#include<malloc.h>

  struct node {
   int data;
   struct node *left;
   struct node *right;
  };

  struct node *newNode(int data){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;

  }

bool isChildSum(struct node *root){

  int left_data=0;
  int right_data=0;
  if(root==NULL || (root->left==NULL && root->right==NULL))
    return true;
    else{
      if(root->left!=NULL)
       left_data=root->left->data;
       if(root->right!=NULL)
        right_data=root->right->data;
        if((root->data==left_data+right_data) && isChildSum(root->left) && isChildSum(root->right))
         return true;
         else
          return false;

    }




}

int main(void){
 struct node *root  = newNode(10);
  root->left         = newNode(8);
  root->right        = newNode(2);
  root->left->left   = newNode(3);
  root->left->right  = newNode(5);
  root->right->right = newNode(2);
   if(isChildSum(root))
     printf("we are done");
     else
     printf("we are struck sucker..");
     return 0;
}

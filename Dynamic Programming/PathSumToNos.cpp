#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

 struct node{
   int data;
   struct node *left;
   struct node *right;
 };
  bool isSumToNos(struct node *,int);



 struct node *newnode(int data){
   struct node *temp=(struct node *)malloc(sizeof(struct node ));
   temp->data=data;
   temp->left=NULL;
   temp->right=NULL;
   return temp;

 }

  bool isSumToNos(struct node *node ,int sum){



   if(node==NULL){
    return(sum==0);
   }
   else{
    bool ans=0;
     int subsum=sum-node->data;
     if(subsum==0 && node->left==NULL && node->right==NULL)
       return 1;

        if(node->left)
          ans=ans || isSumToNos(node->left,subsum);

        if(node->right)
          ans= ans || isSumToNos(node->right,subsum);

          return ans;
   }


  }
  int main()
{

  int sum = 14;

  /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
  struct node *root = newnode(10);
  root->left        = newnode(8);
  root->right       = newnode(2);
  root->left->left  = newnode(3);
  root->left->right = newnode(5);
  root->right->left = newnode(2);

  if(isSumToNos(root, sum))
    printf("There is a root-to-leaf path with sum %d", sum);
  else
    printf("There is no root-to-leaf path with sum %d", sum);

  getchar();
  return 0;
}

// this solution is in the worst case....skewed trees...O(n^2) complixity...

#include<stdio.h>
#include<malloc.h>

struct node{
int data;
struct node *left;
struct node *right;

};

//......................................................................
int printSpiral(struct node *);
int printGivenLevel(struct node *,int ,int);
struct node *newNode(int);
int height(struct node *);
//'.........................................................................

 int printSpiral(struct node *root){
   int h=height(root);
   int i;
   bool ltr=false;
   for(i=1;i<=h;i++){
    printGivenLevel(root,i,ltr);
    ltr=!ltr;
   }
 }

 int printGivenLevel(struct node *root,int level,int ltr){
   if(root==NULL)
     return 0;

     if(level==1)
      printf("%d",root->data);
      else if(level>1){
      if(ltr){
       printGivenLevel(root->left,level-1,ltr);
       printGivenLevel(root->right,level-1,ltr);

      }
      else{
        printGivenLevel(root->right,level-1,ltr);
        printGivenLevel(root->left,level-1,ltr);

      }

 }
}
 int height(struct node *node){
  if(node==NULL)
    return 0;
    else{
     int lheight=height(node->left);
     int rheight=height(node->right);

       if(lheight>rheight)
         return (lheight+1);
         else
           return (rheight+1);
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
   struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(7);
    root->left->right = newNode(6);
    root->right->left  = newNode(5);
    root->right->right = newNode(4);
    printf("Spiral Order traversal of binary tree is \n");
    printSpiral(root);

    return 0;
 }

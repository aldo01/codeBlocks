
#include<stdio.h>
#include<malloc.h>

struct node{
int data;
struct node *left;
struct node *right;
};

int PrintLevelOrder(struct node *);
int printGivenLevel(struct node *,int);
struct node *newNode(int);
int height(struct node *);

int PrintLevelOrder(struct node *root){
  int h=height(root);
  for(int i=1;i<=h;i++){
  printGivenLevel(root,i);
  }

}
int printGivenLevel(struct node *root,int level){
if(root==NULL)
  return 0;
  if(level==1){
   printf(" %d ",root->data);
   printf("\n");
   }
   else if(level>1){
     printGivenLevel(root->left,level-1);
     printGivenLevel(root->right,level-1);
   }
}

 int height(struct node *node){
  if(node==NULL)
    return 0;
    else{
    int lheight=height(node->left);
    int rheight=height(node->right);

       if(lheight>rheight)
         return(lheight+1);
         else
            return(rheight+1);
    }

 }
  struct node *newNode(int new_data){
    struct node *node=(struct node *)malloc(sizeof(struct node));
    node->data=new_data;
    node->left=NULL;
    node->right=NULL;
  }

  int main(void){
    struct node *root = newNode(16);
  root->left        = newNode(20);
  root->right       = newNode(93);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);

  printf("Level Order traversal of binary tree is \n");
  PrintLevelOrder(root);

  getchar();
  return 0;

  }

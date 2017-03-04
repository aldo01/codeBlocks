#include<stdio.h>
#include<malloc.h>



struct node{
 int data;
 struct node *left;
 struct node *right;
};

//..............................
struct node *newNode(int);
int height(struct node *);
int PrintLevelOrderSpiral(struct node *);
int printGivenLevel(struct node *, int, bool);
//................................................


struct node *newNode(int newData){
   struct node *temp=(struct node *)malloc(sizeof(struct node));
   temp->data=newData;
   temp->left=NULL;
   temp->right=NULL;
   return temp;
}

 int height(struct node *root){
  if(root==NULL)
    return 0;
  else{
    int lheight=height(root->left);
    int rheight=height(root->right);

    if((lheight>rheight))
        return lheight+1;
    if(rheight>lheight)
         return rheight+1;
  }
 }


 int main(void){
    struct node *root = newNode(16);
  root->left        = newNode(20);
  root->right       = newNode(93);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);

  printf("Level Order traversal of binary tree is \n");
  PrintLevelOrderSpiral(root);

  getchar();
  return 0;

  }

  int PrintLevelOrderSpiral(struct node *root){
    int h=height(root);
    bool ltr=false;
    for(int i=1;i<=h;i++){
        printGivenLevel(root,i,ltr);
        ltr=!ltr;
    }
  }

  int printGivenLevel(struct node *root, int level, bool ltr){
       if(root==NULL)
     return 0;

    if(level==1)
        printf(" %d ", root->data);

    else if(level>1){
            if(ltr){
         printGivenLevel(root->left, level-1,ltr);
         printGivenLevel(root->right, level-1,ltr);
            }
            else{
                    printGivenLevel(root->right, level-1, ltr);
                printGivenLevel(root->left, level-1, ltr);

            }
    }
  }

#include<stdio.h>
#include<malloc.h>

struct node {
int data;
struct node *left;
struct node *right;
};
//struct node *newNode(int);

struct node *newNode(int data){
struct node *node=(struct node *)malloc(sizeof(struct node ));
node ->data=data;
node->left=NULL;
node->right;
return(node);

}

int IdenticalTree(struct node *a,struct node *b){

if (a==NULL && b==NULL)
  return 1;

  if(a!=NULL && b!=NULL){
  return (
  a->data==b->data && IdenticalTree(a->left,b->left) &&
    IdenticalTree(a->right,b->right)
  );

  }
  return 0;

}

int main(void){
struct node *tree1,*tree2;
tree1=newNode(9);
tree1->left=newNode(6);
tree1->right=newNode(121);

 tree2=newNode(9);
 tree2->left=newNode(6);
 tree2->right=newNode(12);

  if(IdenticalTree(tree1,tree2))
   printf("trees are same");

   else{
   printf("trees are not same");


   }

return 0;

}


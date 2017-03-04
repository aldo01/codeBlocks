#include<stdio.h>
#include<malloc.h>

 struct Tnode{
  int data;
  struct Tnode *left;
  struct Tnode *right;

 } ;

 struct Tnode *newNode(int);
 int inorder(struct Tnode *);
 int traversal(struct Tnode *);

   int main(){
    struct Tnode *root1 = newNode(15);
    struct Tnode *root2 = newNode(15);

    root1->left= newNode(9);
    root1->right = newNode(12);
    root1->left->right = newNode(10);

    root2->left= newNode(12);
    root2->right = newNode(9);
    root2->right->left = newNode(10);

    printf("inorder of first tree...\n");
    inorder(root1);

    printf("\ntraversal of roo2...\n");
      traversal(root2);



    return 0;
   }


struct Tnode *newNode(int new_data){
  struct Tnode *temp=(struct Tnode *)malloc(sizeof(struct Tnode));
  temp->data=new_data;
  temp->left=NULL;
  temp->right =NULL;
  return temp;
};

  int inorder(struct Tnode *node){
 if(node==NULL)
    return 0;
    printf(" %d ",node->data);
    inorder(node->left);
   // printf(" %d ",node->data);
    inorder(node->right);
 }
 int traversal(struct Tnode *node){
 if(node==NULL)
    return 0;
    printf(" %d ",node->data);
    inorder(node->right);
    inorder(node->left);
   // printf(" %d ",node->data);

 }



#include<stdio.h>
#include<malloc.h>

struct node {
int data;
struct node *left;
struct node *right;
};
struct node*LCA(struct node *, int,int);
struct node *newNode(int);
int main(void){
struct node *root;
root=newNode(20);
root->left=newNode(8);
root->right=newNode(22);
root->left->left=newNode(4);
root->left->right=newNode(12);
root->left->right->left=newNode(10);
root->left->right->right=newNode(14);
 //
 int n1=10,n2=14;
 struct node *t=LCA(root,n1,n2);
 printf("lca of %d and %d is %d",n1,n2,t->data);
}

struct node * LCA(struct node *root,int n1,int n2){
  if(root==NULL)
    return 0;

    if(root->data>n1 && root->data>n2)
     return LCA(root->left,n1,n2);

     if(root->data<n1 && root->data<n2)
       return LCA(root->right,n1,n2);


    return root;

}

struct node *newNode(int new_data){
  struct node *node=(struct node *)malloc(sizeof(struct node ));
  node->data=new_data;
  node->left=NULL;
  node->right=NULL;
  return(node);


}


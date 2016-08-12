#include<stdio.h>
#include<malloc.h>

struct node{
int data;
struct node *left;
struct node *right;
};

int size(struct node *root){
if(root==NULL)
return 0;

return(size(root->left)+1+size(root->right));
}
struct node *newNode(int data){
struct node *node=(struct node *)malloc(sizeof(struct node));
node->data=data;
node->left=NULL;
node->right=NULL;
return(node);

}

int main(void){
struct node *root;
root=newNode(20);
root->left=newNode(8);
root->right=newNode(22);
root->left->left=newNode(4);
root->left->right=newNode(12);
root->left->right->left=newNode(10);
root->left->right->right=newNode(14);
printf("size of the tree is %d ",size(root));
}

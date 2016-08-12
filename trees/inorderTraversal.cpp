#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct treenode{
int data;
struct treenode *left;
struct treenode *right;

};
struct treenode *new_node(int);
int preorder(struct treenode *);
int postorder(struct treenode *);
int inorder(struct treenode *);
int main(void){
 struct treenode *root;
 root=new_node(1);
 root->left=new_node(2);
 root->right=new_node(3);
 root->left->left=new_node(4);
 root->left->right=new_node(5);

  preorder(root);
  postorder(root);
  inorder(root);

  return 0;

}

struct treenode *new_node(int new_data){
 struct treenode *node=(struct treenode *)malloc(sizeof(struct treenode));
 node->data=new_data;
 node->left=NULL;
 node->right=NULL;
 return(node);
}
int postorder(struct treenode *node){
if(node==NULL)
 return 0 ;
 postorder(node->left);
 postorder(node->right);
 printf(" %d ",node->data);

}
int inorder(struct treenode *node){
if(node==NULL)
return 0;

inorder(node->left);
printf(" %d ",node->data);
inorder(node->right);

}
int preorder(struct treenode *node){
 printf(" %d ",node->data);
 preorder(node->left);
 preorder(node->right);

}

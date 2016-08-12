#include<stdio.h>
#include<malloc.h>

struct node{
 int data;
 struct node *left;
 struct node *right;
};

struct node *newNode(int);

int countNodes(struct node *root){
 if(root==NULL)
   return 0;
   if(root->left==NULL && root->right==NULL)
     return 1;

     return countNodes(root->left)+countNodes(root->right);

}

int main(){
 struct node *root=newNode(4);
 root->left=newNode(2);
 root->right=newNode(5);
 root->left->left=newNode(1);
 root->left->right=newNode(3);
 printf("number of nodes are %d",countNodes(root));
 return 0;

}

struct node *newNode(int data){
 struct node *temp=(struct node *)malloc(sizeof(struct node ));
 temp->data=data;
 temp->left=NULL;
 temp->right=NULL;
 return temp;
}

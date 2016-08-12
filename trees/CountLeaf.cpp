#include<stdio.h>
#include<malloc.h>

struct node {
 int data;
 struct node *left;
 struct node *right;

};

int countLeaf(struct node *);
struct node *newNode(int);
int Insert(struct node *,int );

int countLeaf(struct node *node){
if(node==NULL)
  return 0;
  if(node->left==NULL && node->right==NULL)
   return 1;
    return countLeaf(node->left)+countLeaf(node->right);
}

struct node *newNode(int data){
  struct node *temp=(struct node *)malloc(sizeof(struct node ));
  temp->data=data;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}

int Insert(struct node *node_ref,int data){
  struct node *root=node_ref;
  if(root==NULL)
   node_ref=newNode(data);
   else{
    if(data<=root->data)
      Insert(root->left,data);
      else
        Insert(root->right,data);
   }
}

int main(){
  struct node root;
   Insert(&root, 4);
    Insert(&root, 2);
    Insert(&root, 1);
    Insert(&root, 3);
    Insert(&root, 5);
    //countLeaf(root);
    printf("leaf nodes are %d",countLeaf(&root));
    return 0;

}

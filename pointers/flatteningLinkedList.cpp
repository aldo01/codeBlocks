#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
int data;
struct node *right;
struct node *down;
};
int push(struct node **,int) ;
struct node *merge(struct node *,struct node *);
struct node *flattenList(struct noed *);
int printList(struct node *);

struct node * flattenList(struct node *root){
 if(root==NULL || root->right==NULL){
 return root;
 }
  return merge(root,flattenList(root->right));

}
 struct node *merge(struct node *a,struct node *b){
  if(a==NULL )
   return b;
   if(b==NULL)
    return b;
    struct node *result;
    if(a->data<=b->data){
    result=a;
    result->down=merge(a->down,b);

    }
 else{
  result=b;
  result->down=merge(a,b->down);
 }
 return(result);
 }


int main(void){
struct node *root=NULL;
push(&root,30);
push(&root,12);
push(&root,7);
push(&root,4);

 push(&(root->right),20);
 push(&(root->right),10);

push(&(root->right->right),50);
push(&(root->right->right),40);
push(&(root->right->right),35);

   root=flattenList(root);
   printList(root);
 return 0;
}

int push(struct node **head_ref,int new_data){

 struct node *temp=(struct node *)malloc(sizeof(struct node ));
 temp->right=NULL;
 temp->data=new_data;
 temp->down=*head_ref;
 *head_ref=temp;

}

int printList(struct node *node){
while(node!=NULL){
printf(" %d ",node->data);
node=node->down;
}

}

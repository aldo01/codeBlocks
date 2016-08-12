/*Given a Singly Linked List which has data members sorted in ascending order.
Construct a Balanced Binary Search Tree which has same data members as the given Linked List. */

#include<stdio.h>
#include<malloc.h>

int push(struct Lnode **,int);
struct Tnode *SortedListToBstRec(struct Lnode **,int);
struct Tnode * ListToBst(struct Lnode *);
int preorder(struct Tnode *);
int countList(struct Lnode *);
struct Tnode *newNode(int);
int inorder(struct Tnode *);

struct Lnode{
int data;
struct Lnode *next;
};

struct Tnode{
int data;
struct Tnode *left;
struct Tnode *right;
};

int main(void){
struct Lnode *head=NULL;
push(&head,1);
push(&head,2);
push(&head,3);
push(&head,4);
push(&head,5);

struct Tnode *root=ListToBst(head);
printf("the constructed tree ..");
preorder(root);
printf("\n");
inorder(root);
return 0;

}

struct Tnode * ListToBst(struct Lnode *head){
int n=countList(head);
 return SortedListToBstRec(&head,n);
}

struct Tnode * SortedListToBstRec(struct Lnode **head_ref,int n){
if(n<=0)
 return 0;

 struct Tnode *left=SortedListToBstRec(head_ref,n/2);
 struct Tnode *root=newNode((*head_ref)->data);
 root->left=left;
 *head_ref=(*head_ref)->next;

 root->right=SortedListToBstRec(head_ref,n-(n/2)-1);
 return root;

}
int push(struct Lnode **head_ref1,int new_data){
struct Lnode *temp=(struct Lnode *)malloc(sizeof(struct Lnode));
temp->data=new_data;
temp->next=*head_ref1;
*head_ref1=temp;

}

int countList(struct Lnode *head){
int count=0;
struct Lnode *temp=head;
while(temp)
{
 temp=temp->next;
 count++;
}
 return count;
}
struct Tnode *newNode(int data){
struct Tnode *node=(struct Tnode *)malloc(sizeof(struct Tnode ));
node->data=data;
node->left=NULL;
node->right=NULL;
}
int preorder(struct Tnode *root){
if(root==NULL)
  return 0;

  printf(" %d ",root->data);
  preorder(root->left);
  preorder(root->right);

}
int inorder(struct Tnode *root){
  if(root==NULL)
    return 0;

     inorder(root->left);
     printf(" %d ",root->data);
     inorder(root->right);


}



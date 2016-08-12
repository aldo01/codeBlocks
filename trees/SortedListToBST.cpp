#include<stdio.h>
#include<malloc.h>

struct Lnode{
  int data;
  struct Lnode *next;
};

struct Tnode{
  int data;
  struct Tnode *right;
  struct Tnode *left;
};

struct Tnode *sortedListToBSTRec(struct Lnode **,int );
struct Tnode *sortedListToBST(struct Lnode *);
int CountNode(struct Lnode *);
int printList(struct Lnode *);
int preorder(struct Tnode *);
struct Tnode *newNode(int);
int push(struct Lnode *,int);

 int CountNode(struct Lnode *head){
   int count=0;
   struct Lnode *temp= head;
   while(temp!=NULL){
    temp=temp->next;
    count++;
   }
   return count;
 }

  struct Tnode *newNode(int new_data){
   struct Tnode *temp=(struct Tnode *)malloc(sizeof(struct Tnode));
   temp->data=new_data;
   temp->left=NULL;
   temp->right=NULL;
   return temp;

  }
  struct Tnode *sortedListToBST(struct Lnode *head){
   int n=CountNode(head);
   return sortedListToBSTRec(&head,n);
  }

  struct Tnode *sortedListToBSTRec(struct Lnode **head_ref,int n){
    if(n<=0)
     return NULL;
     struct Tnode *left=sortedListToBSTRec(head_ref,n/2);

      struct Tnode *root=newNode((*head_ref)->data);
      root->left=left;
      *head_ref=(*head_ref)->next;
      root->right=sortedListToBSTRec(head_ref,n-n/2-1);
      return root;
  }
  int push(struct Lnode **head_ref,int new_data){

   struct Lnode *node=(struct Lnode*)malloc(sizeof(struct Lnode));
   node->data=new_data;
   node->next=(*head_ref);
   *head_ref=node;
//   return node;
  }

  int main(int argc,char *argv[]){
   struct Lnode *head;
   push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

   printf("given linled list is");
   printList(head);
   struct Tnode *root=sortedListToBST(head);
   printf("preorder traversal of tree is");
   preorder(root);
   return 0;

  }

  int printList(struct Lnode *head){
   //struct Lnode *temp=head;
   while(head!=NULL){
    printf(" %d ",head->data);
     head=head->next;
   }
  }

  int preorder(struct Tnode *root){
   if(root==NULL)
     return 0;

     printf(" %d ",root->data);
     preorder(root->left);
     preorder(root->right);
  }

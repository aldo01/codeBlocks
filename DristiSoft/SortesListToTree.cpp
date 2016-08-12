#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

int push(struct lnode ** , int);
struct tnode *sortedListToBST(struct lnode *);
struct tnode *sortedListToBSTRec(struct lnode **, int);
int printList(struct lnode *);
int countList(struct lnode *);
int printPreorder(struct tnode *);

struct lnode{
 int ldata;
 struct lnode *next;
};

struct tnode{
 int tdata;
 struct tnode *left;
 struct tnode *right;

};

int main(void){
 struct lnode *head=NULL;
 push(&head,9);
 push(&head,8);
 push(&head,7);
 push(&head,6);
 push(&head,5);
 push(&head,4);
 push(&head,3);
 push(&head,2);
 printf("linked list :\n");
 printList(head);
 printf("tree preorder is :\n");
 struct tnode *root=sortedListToBST(head);
 printPreorder(root);
 return 0;
}

  int push(struct lnode **head_ref, int data){
   struct lnode *temp=(struct lnode *)malloc(sizeof(struct lnode));
   temp->ldata=data;
   temp->next=*head_ref;
   *head_ref=temp;

  } 6

  struct tnode *newNode(int data){
   struct tnode *temp=(struct tnode *)malloc(sizeof(struct tnode));
   temp->tdata=data;
   temp->left=NULL;
   temp->right=NULL;

  }
  struct tnode *sortedListToBST(struct lnode *head){
  int n=countList(head);
  return sortedListToBSTRec(&head,n);
  }
  struct tnode *sortedListToBSTRec(struct lnode **head_ref,int n){
     if(n<=0)
     return NULL;
     struct tnode *left=sortedListToBSTRec(head_ref,n/2);
     struct tnode *root=newNode((*head_ref)->ldata);

     root->left=left;
     (*head_ref)= (*head_ref)->next;

     root->right=sortedListToBSTRec(head_ref,n-n/2-1);
     return root;
  }

  int printList(struct lnode *head){
      while(head!=NULL){
        printf("< %d >",head->ldata);
        head=head->next;

      }
  }
   int countList(struct lnode *head){
     int count=0;
     struct lnode *temp=head;
      while(temp!=NULL){
       temp=temp->next;
       count++;
      }
      return count;
       }

  int printPreorder(struct tnode *root){
    if(root==0)
    return NULL;

    printPreorder(root->left);
    printf( " %d ",root->tdata);
    printPreorder(root->right);
  }

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

 struct tnode{
  int data;
  struct tnode *left;
  struct tnode *right;
 };

 struct snode{
 struct tnode *t;
 struct snode *next;
 };

  struct tnode *newNode(int data){
    struct tnode *temp=(struct tnode *)malloc(sizeof(struct tnode));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
  }

   int Inorder(struct tnode *root){
    struct tnode *current=root;
    struct snode *s=NULL;
     bool done=0;
     while(!done)
     {
      if(current!=NULL){
       push(&s,current);
       current=current->left;
     }
     else{
       if(!empty(s)){

       }
     }

   }

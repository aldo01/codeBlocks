#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

  struct node{
   int data;
   struct node *left;
   struct node *right;
  };

  struct node *newNode(int data){
   struct node *temp=(struct node *)malloc(sizeof(struct node));
   temp->data=data;
   temp->left=NULL;
   temp->right=NULL;
   return temp;
  }

  int



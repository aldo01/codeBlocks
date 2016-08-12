#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct lnode{
 int data;
 struct lnode *next;
};

struct tnode{
 int tdata;
 struct tnode *left;
 struct tnode *right;
};
int main(){
 struct node *tnode=NULL;

}

struct tnode *newNode(int data){
  struct tnode *temp=(struct tnode *)malloc(sizeof(struct tnode));
  temp->tdata=data;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}


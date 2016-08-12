#include<stdio.h>
#include<malloc.h>
struct node{
int data;
struct node *left;
struct node *right;
};

int printArray(int [],int);
int pathToleaf(struct node *);
int pathToleafRec(struct node *,int [],int);


int pathToleaf(struct node *head){
int path[1000];
return pathToleafRec(head,path,0);
}

int pathToleafRec(struct node *head,int path[],int pathlen){
if(head==NULL)
  return 0;

  path[pathlen]=head->data;
  pathlen++;
  if(head->left==NULL && head->right==NULL){
  printArray(path,pathlen);
  }
  else{
   pathToleafRec(head->left,path,pathlen);
   pathToleafRec(head->right,path,pathlen);
  }


}

struct node *newNode(int new_data){
 struct node *node=(struct node *)malloc(sizeof(struct node));
 node->data=new_data;
 node->left=NULL;
 node->right=NULL;
}

int printArray(int arr[],int len){
int i=0;
for(i=0;i<len;i++){
   printf(" %d ",arr[i]);
}
printf("\n");
}

int main(void){
struct node *head=newNode(12);
head->left=newNode(8);
head->right=newNode(16);
head->left->right=newNode(9);
head->left->left=newNode(7);
head->right->left=newNode(14);
  pathToleaf(head);
}

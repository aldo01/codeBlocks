#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
int value;
struct node *left;
struct node *right;
};


typedef struct node Node;
Node * create_node(int value){
Node * temp = (Node *)malloc(sizeof(Node));
temp->value = value;
temp->right= NULL;
temp->left = NULL;
return temp;
}
Node * addNode(Node *node, int value){
if(node == NULL){
return create_node(value);
}
else{
if (node->value > value){
node->left = addNode(node->left, value);
}
else{
node->right = addNode(node->right, value);
}
}
return node;
}

void treeToList(Node *node){

Queue *queue = NULL;
Node * last = NULL;
if(node == NULL)
return ;

enqueue(&queue, node);
while(!isEmpty(queue)){
/* Take the first element and put both left and right child on queue */
node = front(queue);
if(node->left)
enqueue(&queue, node->left);
if(node->right)
enqueue(&queue, node->right);
if(last != NULL)
last->right = node;
node->left = last;
last = node;
dequeue(&queue);

}

}
/* Driver program for the function written above */
int main(){
Node *root = NULL;
//Creating a binary tree
root = addNode(root,30);
root = addNode(root,20);
root = addNode(root,15);
root = addNode(root,25);
root = addNode(root,40);
root = addNode(root,37);
root = addNode(root,45);
treeToList(root);
return 0;
}

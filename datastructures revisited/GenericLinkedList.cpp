#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node {
 void *data;
 struct node *next;
};
void push(struct node **,void *,size_t);
void printList(struct node *,void *);
void printInt(void *);
void printFloat(void *);
//.................................

void push(struct node **head_ref,void *new_data,size_t data_size){
 struct node *new_node=(struct node *)malloc(sizeof(struct node ));
 new_node->data=malloc(data_size);
 new_node->next=*head_ref;
 int i;
  for(i=0;i<data_size;i++)
    *(char *)(new_node->data+i)=*(char *)(new_data+i);
    *head_ref=new_node;
}
 void printInt(void *n){
  printf("%d",*(int *)n);
 }
 void printFloat(void *n){
  printf("%f",*(float *)n);
 }
 void printList(struct node *node,void (*fptr)(void *)){
  while(node!=NULL){
   (*fptr)(node->data);
        node = node->next;
  }
 }
int main(void){
 struct node *start=NULL;
 unsigned int_size=sizeof(int);
 int arr[]={12,23,1,4,55},i;
 for(i=4;i>=0;i--)
  push(&start,&arr[i],int_size);
  printf("created linked list of int");
  printList(start,printInt);
  //.........................
  start=NULL;
  unsigned float_size=sizeof(float);
  float a[]={12.0,2.5,61.3,9.0,30.4};
  for(i=4;i>=0;i--)
   push(&start,&a[i],int_size);
   printf("created linked list of float");
   printList(start,printFloat);
   return 0;
}

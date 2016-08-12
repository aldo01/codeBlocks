#include<stdio.h>
#include<malloc.h>

 struct node{
 int data;
 struct node *next;

 };
 int push(struct node **,int);
 int count(struct node *);
 int nthFromLast(struct node *,int,int);



  int main(){
    struct node *Head,*p;
    int l,j,len;
    push(&Head,2);
    push(&Head,34);
    push(&Head,44);
    push(&Head,65);
    push(&Head,90);
   // int len;
    len=count(Head);
    printf("length of list is = %d",len);
    printf("enter the elemnt ");
    scanf("%d",&l);
    nthFromLast(Head,len,3);

  }

  int count(struct node *head){
     int i;
     struct node *current;
     int count=0;
     while(current!=NULL){
       count++;
       current=current->next;
     }
      return count;

  }


    int push(struct node **new_head,int new_data){
      struct node *p=(struct node *)malloc(sizeof(struct node));
      p->data=new_data;
      p->next= *(new_head);
      *new_head=p;

      }
      int nthFromLast(struct node *Head,int len,int j){
        struct node *temp;
        int i;
        if(len<j)
          printf("index out of bound");

           temp=Head;
           for(i=1;i<len-j+1;i++)
            temp=temp->next;
            printf("%d",temp->data);




      }



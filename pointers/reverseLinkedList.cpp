#include<stdio.h>
 #include<malloc.h>


  struct node{
    int data;
    struct node *next;

  };
     int reverseList(struct node **);
     int push(struct node **,int );
     int print(struct node *);
    int main(){
     struct node *Head=NULL;
     push(&Head,23);
     push(&Head,12);
     push(&Head,44);
     push(&Head,32);
     push(&Head,91);
     print(Head);
     reverseList(&Head);
     print(Head);

    }
     int push(struct node **head,int new_data){
      struct node *temp;
      temp=(struct node*)malloc(sizeof(struct node));
       temp->data=new_data;
       temp->next=*head;
       *head=temp;

     }
      int reverseList(struct node **head){
        struct node *result=NULL;
        struct node *current=*head;
        struct node *next;
        while(current!=NULL){
          next=current->next;
           result=current->next;
            current=next;
        }
          *head=result;
         // print(*head);

      }
  int print(struct node *Head){

  struct node *temp;

  if(Head != NULL)
  {
    temp = Head;
    printf("\n");
    do {
      printf("%d ", temp->data);
      temp = temp->next;
    } while(temp != Head);
  }
}



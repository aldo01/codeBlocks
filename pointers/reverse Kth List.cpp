#include<stdio.h>
#include<malloc.h>
#include<time.h>


   struct node{
     int data;
     struct node *next;
     };


      int push(struct node **,int);
      int print(struct node *);
      struct node *reverseKth(struct node *,int);

   int main(){
    struct node *head=NULL;
    int k,i;
    clock_t t;
    t=clock();
    for(i=20;i>0;i--){
      push(&head,i);
    }
    printf("original list\n");
    print(head);
    head=reverseKth(head,3);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
     printf("rev() took %f seconds to execute \n", time_taken);


    printf("new list\n");
    print(head);
    return 0;
   }
     int push(struct node **head_ref,int new_data){
        struct node *temp=*head_ref;
        temp=(struct node *)malloc(sizeof(struct node ));
        temp-> data=new_data;
        temp->next=*head_ref;
        *head_ref=temp;
     }

     struct node *reverseKth(struct node *head,int k){
     printf("reverse running");
     printf("enter to stop");
     while(1){
     if(getchar()){
       break;
     }
       struct node *current=head;
       struct node *next;
       struct node *prev;
       int count=0;
       while(current!=NULL&&count<k){
         next=current->next;
         current->next=prev;
        // prev=current->next;
         prev=current;
         current=next;
         count++;
         }
          if(head!=NULL){
          head->next=current;
          }
          count =0;
          while(count<k && current!=NULL){
           current=current->next;
           count++;
          }
          if(current!=NULL)
          current->next=reverseKth(current->next,k);
         return prev;

     }
}

     int print(struct node *node){
     int count=0;
      while(node!=NULL){
       printf(" <%d> ",node->data);
         node=node->next;
         count++;
      }
     }

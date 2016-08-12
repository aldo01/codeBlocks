#include<stdio.h>
#include<malloc.h>

 struct stack{
  char data;
  struct stack *next;

 };
  int init( struct stack **);
  int empty(struct stack*);
  char pop(struct stack**);
  int push(struct stack **,char);

  int main(){
   struct stack *top;
   char x;
   init(&top);
   printf("enter the string\n");
   while((x=getchar())!='\n'){
    push(&top,x);
   }
   printf("\n");
   while(!empty(top)){
    x=pop(&top);
    printf("%c",x);
   }
  }
  int init(struct stack **t){
    *t=NULL;
  }
  int empty(struct stack *top){
   if(top==NULL)
     return(1);
     return(0);
  }
int push(struct stack **t,char x){

   struct stack *p;
   p=(struct stack *)malloc(sizeof(struct stack));
   p->data=x;
   p->next=*t;
   *t=p;
}
char pop(struct stack **t){
  char x;
  struct stack *p;
  p=*t;
  *t=p->next;
  x=p->data;
  free(p);
  return(x);

}

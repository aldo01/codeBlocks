#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MAX 30


void push(struct stack1 *,char);
char pop(struct stack1 *);
int empty1(struct stack1 *);
int full(struct stack1 *);




  struct stack1{
    int top;
    char data[MAX];

};



  int main(void){
    struct stack1 *t;
    char x;
    printf("enter the nos");
    while((x=getchar())!='\n'){
      if(!ful(t))
       push(t,x);
       else
         printf("stack is full");
        exit(0);
    }
    printf("\n result=");
    while(!=empty1(t)){
     x=pop(t);
     printf("%c",x);
    }



  }
  int init(struct stack1 *p){
   p->top=-1;
  }
  int empty1(struct stack1 *p){
    if(p->top==-1)
     return(1);
     else
       return 0;
  }
   int full(struct stack1 *p){
     if(p->top==MAX-1)
      return (1);
      else
        return (0);

   }

void push(struct stack1 *p,char new_data){
  if(!full(p)){
   p->top=p->top+1;
   p->data[p->top]=new_data;
  }
  else
     printf("stack is full");

}

char pop(struct stack1 *p){
char x;
  if(!empty1(p)){
    x=p->data[p->top];
    p->top=p->top-1;
  }
  return(x);
}


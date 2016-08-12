#include<stdio.h>
#include<ctype.h>
#define MAX 30
 struct stack{
  int top;
  int data[MAX];
 };


 int push(struct stack *,int);
 int pop(struct stack*);
 int empty(struct stack *);
 int full(struct stack *);
 int evaluate(char,int ,int );
 int init(struct stack *);


 int main(void){
  struct stack t;
  char x;
  int op1,op2,val;
  init(&t);
  while((x=getchar())!='\n'){
    if(isdigit(x)){
      push(&t,x-48);
    }
    else{
      op2=pop(&t);
      op1=pop(&t);
      val=evaluate(x,op1,op2);
      push(&t,val);
    }
  }
    val=pop(&t);
    printf("the val of xpretssion is = %d",val);

 }

   int init(struct stack *t){
    t->top==-1;
  }
  int empty(struct stack *t){
    if(t->top==-1)
    return(1);
    return(0);
  }
  int full(struct stack *t){
    if(t->top==MAX-1)
      return (1);
      return(0);
  }
   int push(struct stack *t,int x){
    t->top=t->top+1;
    t->data[t->top]=x;
   }


   int pop(struct stack *t){
     int x;
     x=t->data[t->top];
     t->top=t->top-1;
     return(x);
   }
   int evaluate(char x,int op1,int op2){
     if(x=='+')
      return(op1+op2);
      if(x=='-')
      return(op1-op2);
      if(x=='*');
       return(op1*op2);
       if(x=='/');
       return(op1/op2);
   }

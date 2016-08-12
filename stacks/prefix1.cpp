#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 50
struct stack{
 int data[MAX];
 int top;
}stack;
int eval(char prefix[]);
int evaluate(char ,int,int);
int empty(stack *);
int push(stack *,int);
int pop(stack *);
int init(stack *);
int full(stack *);


int main(){
  char prefix[30];
  printf("enter the prefix expression");
  gets(prefix);
  eval(prefix);
//  getch();
  return 0;

}
int eval(char prefix[]){
 stack s;
 char x;
 int op1,op2,val,i;
 init(&s);
 for(i=strlen(prefix)-1;i>=0;i--){
    x=prefix[i];
   if(isalpha(x)){
   printf("enter the value of %c",x);
   scanf("%d",&val);
   push(&s,val);
   }
    else{
     op1=pop(&s);
     op2=pop(&s);
     val=evaluate(x,op1,op2);
     push(&s,val);

    }

 }
   val=pop(&s);
   printf("final value is = %d",val)
}
int evaluate(char x,op1,op2){
  if(x='+')
  return(op1+op2);
  if(x='-') return(op1-op2);
  if(x='/') return(op1/op2);
  if(x='*') return(op1*op2);

}
int init(stack *s){
 s->top=-1;
}
int push(stack *s,int x){
 s->top=s->top+1;
 s->data[s->top]=x;
}
int pop(stack *s){
 int x;
 x=s->data[s->top];
 s->top=s->top-1;
 return(x);
}

int empty(stack *s){
 if(s->top==-1)
 return(1);
 return(0);
}
int full(stack *s){
if(s->top==MAX-1)
return(1);
return(0);

}

#include<stdio.h>
#include<malloc.h>
#define MAX 30


int push(stack1 *,char);
int pop(stack1 *);
int empty1(stack1 *);
int full(stack1 *);




  struct stack1{
    int top;
    char data[MAX];

};



  int main(){
    struct stack1 *t=NULL;
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
    while(!empty1(t)){
     x=pop(t);
     printf("%c",x);
    }



  }
  int init(stack1 *p){
   p->top=-1;
  }
  int empty1(stack1 *p){
    if(p->top==-1)
     return(1);
     else
       return 0;
  }
   int full(stack1 *p){
     if(p->top==MAX-1)
      return (1);
      else
        return (0);

   }

int push(stack1 *p,char new_data){
  if(!full(p)){
   p->top=p->top+1;
   p->data[p->top]=new_data;
  }
  else
     printf("stack is full");

}

int pop(stack1 *p){
char x;
  if(!empty1(p)){
    x=p->data[p->top];
    p->top=p->top-1;
  }
  return(x);
}


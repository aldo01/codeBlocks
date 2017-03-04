#include<stdio.h>

  int main(){
    int n;
    for(;;){
      scanf("%d",&n);
      if(n<0){
      printf("Goodbye!");
      break;
      }

       if(n%5!=0)
           continue;

       if(n%5==0)
          printf("%d",n/5);

    }
    return 0;
  }

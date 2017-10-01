#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n;
    char *str="min(int,int)";
    scanf("%d",&n);
    if(n==2){
      printf("%s",str);
    }
    else{
               for(int i=3;i<=n;i++){
                str="min(int,"str")";
             }
             }

    return 0;
}

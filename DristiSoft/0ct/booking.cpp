#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 10
int factorial(int);
int multiply(int, int [], int);

int main() {
  int n,m,c,unq1,unq2,FinalLocation;
  scanf("%d %d %d",&n,&m,&c);
   if((n<11 && m<11) && (c<n && c<m) ){
        unq1= n-c;
        unq2= m-c;
        FinalLocation= unq1+unq2+c-1;
        factorial(FinalLocation);
   }



    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

int factorial(int n){
    int res[MAX];
    int res_size=1;
    res[0]=1;
    for(int x=2;x<=n;x++)
       res_size=multiply(x,res,res_size);

     for(int i=res_size-1;i>=0;i--)
       printf("%d",res[i]);
}

int multiply(int x, int res[], int res_size){
    int carry=0;
    for(int i=0;i<res_size;i++){
        int prod=(res[i]*x)+carry;
         res[i]=prod%10;
       carry=prod/10;
    }
    while(carry){
        res[res_size]=carry%10;
         carry=carry/10;
          res_size++;
    }
     return res_size;
}

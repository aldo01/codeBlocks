#include<stdio.h>
#include<malloc.h>

 int fib(int);

int main(){
 int n=999;
 fib(n);
 return 0;
}

int fib(int n){
 long long f[n+1];
 long long i;
 f[0]=0;
 f[1]=1;
 printf(" %d %d ", f[0],f[1]);
 for(i=2;i<n;i++){
    f[i]=f[i-1]+f[i-2];
    printf(" %d ", f[i]);
 }
 return f[n];
}

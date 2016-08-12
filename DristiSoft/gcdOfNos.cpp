
#include<stdio.h>

#include<stdio.h>

int Gcd(int,int);
int FindMax(int,int);
int FindMin(int,int);

int main(){
 int n=2,m=5;
 //int n=27,m=21;
// int n,m;
 //scanf("&d %d",&n,&m);
 printf("%d",Gcd(n,m));
 return 0;
}

int Gcd(int n,int m){
 if(n==m)
   return n;

   if(n>m)
     return Gcd(n-m,m);

     return Gcd(n,m-n);

}



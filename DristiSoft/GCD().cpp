#include<stdio.h>

int Gcd(int,int);
int swap(int *, int *);
int main(){
 int n=27,m=21;
 //printf("hbcffjkdhfjldhflk");
 //printf("hbcffjkdhfjldhflk");
// scanf("&d %d",&n,&m);
 printf("%d",Gcd(n,m));
 return 0;
}

int Gcd(int n,int m){
    //if(n<m)
    //swap(&n,&m);
    int k=n%m;

    if(k==1)
        return m;
  return Gcd(k,(m%k));
 }

int swap(int *n, int *m){
 int *temp;
 *temp=*n;
 *n=*m;
 *m=*temp;
}

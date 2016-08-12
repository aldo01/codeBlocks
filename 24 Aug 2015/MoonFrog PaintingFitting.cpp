
#include <stdio.h>
 int  paintingSize(int,int ,int,int,int,int);
int main()
{
     int n,m,a,b,c,d;
   scanf("%d %d",&n,&m);
   scanf("%d %d",&a,&b);
   scanf("%d %d",&c,&d);
   printf("go");
     paintingSize(n,m,a,b,c,d);
     return 0;
     }


     int  paintingSize(int n,int m ,int a,int b,int c,int d){
   if(n>m){

   if(n<a || n<b){
   	printf("No");
   }

   if(n<c || n<d){
   	printf("No");
   }
}
  else if(n<m){

  	if(m<a || m<b){
  		printf("No");
  	}
  	if(m<c || m<d){
  		printf("No");
  	}
  }
  else{
    printf("Yes");
     }

}

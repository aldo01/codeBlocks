#include<stdio.h>
#include<string.h>
#include<string>
#include<stdlib.h>

int lcs(char[], char[], int, int);
int lps(char[],char[], int, int);
char *strrev(char *);
int max(int , int);
int main(){

  char X[]="ABABA";
  int n = strlen(X);
  char *Y=strrev(X);
  char *K= (char *)malloc(sizeof(char )*n+1);
  K  = Y;
  printf(" %s ", K);
  printf(" %d ", lps(X,K,0,n-1));

  return 0;
}

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

 int lps(char *x,char * y, int f, int l){

   int m,n;
   m=n=strlen(x);
   printf(" %d ",m);
   int k = lcs(x,y,m,n);
   return k;
 }

 int lcs( char *X, char *Y, int m, int n )
{
   int L[m+1][n+1];
   int i, j;


   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;

       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;

       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }


   return L[m][n];
}int max(int a, int b){
  return (a>b) ? a :b ;
}

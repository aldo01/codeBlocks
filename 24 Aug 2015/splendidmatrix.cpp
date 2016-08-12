#include <iostream>
#include<cmath>
using namespace std;


int A[1024][1024];
void splidem(int n,int s,int a,int b){

	if(n>1){

	    int p=pow(2,n-1)*pow(2,n-1);
	    int k=pow(2,n)/2;
	    splidem(n-1,s,a,b);
	    splidem(n-1,s+p,a,b+k);
	    splidem(n-1,s+p*2,a+k,b);
	    splidem(n-1,s+p*3,a+k,b+k);


	}
	 else if(n==1){

	     A[a][b]=s;
	     A[a][b+1]=s+1;
	     A[a+1][b]=s+2;
	 	 A[a+1][b+1]=s+3;
	 }

	}



int main()
{
  int n;
  cin>>n;
  int N=pow(2,n);
  splidem(n,1,0,0);
  for(int i=0;i<N;i++){
   for(int j=0;j<N;j++){
       cout<<  A[i][j]  <<" ";}
       cout<<endl;
  }
}

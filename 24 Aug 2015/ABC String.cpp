#include <stdio.h>
long long expomod(long long n,long long pow,long long mod)
{
	long long res=1;
	while(pow>0)
	{
		if(pow&1)
		res=((res%mod)*(n%mod))%mod;
		pow=pow>>1;
		n=(((n)%mod)*(n%mod))%mod;
	}
	return res;
}

int main()
{
   // printf("Hello World!\n");
   long long t,n,mod=1000000007,ans;
   scanf("%lld",&t);
   while(t--)
   {
   	scanf("%lld",&n);
   	if(n<=2)
   	printf("0\n");
   	else
   	{
   		ans=(3*(expomod(3,n-1,mod)-expomod(2,n,mod)+1))%mod;
   		if(ans<0)
   		ans+=mod;
   		printf("%lld\n",ans);
   	}

   }
    return 0;
}

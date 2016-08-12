#include<stdio.h>
#include<string.h>
#include<math.h>
//#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>

int factorial(int n)
{
	if(n==1 || n==0) return 1;
	else return n*factorial(n-1);
}

bool judge(int n)
{
	char s[10];
	sprintf(s,"%d",n);
	int len=strlen(s);
	int sum=0;
	for(int i=0; i<len; i++)
	{
		sum+=factorial(s[i]-'0');
	}

	if(sum%n==0) return true;
	else return false;
}


int main()
{
    int n;
    scanf("%d",&n);
	int sum=0;
	for(int i=10; i<=n; i++)
	{
		if(judge(i))
			sum+=i;
	}
	printf("%d\n",sum);
	return 0;
}

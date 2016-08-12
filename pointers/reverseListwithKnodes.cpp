#include <stdio.h>
int sizeCount(int);
int numberOf2sBetween0AndN(int n)
	{
		// write your code here
		int count =0;
		int size=0;
		int i;

		for(i=0;i<=n;i++)
		//size=sizeCount(n);
		for(i=1;i<=n;i++){
		 size=sizeCount(n);



			while(size){
			i=i%10;
			if(i==2){
				count++;

			}
			i=i/10;
			size--;



			}
		}


		return count;
	}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",numberOf2sBetween0AndN(n));
	return 0;
}

int sizeCount(int n){
	int s=0;
	while(n!=0){
		n=n/10;
		s++;
	}
	return s;
}

#include<bits/stdc++.h>
using namespace std;
int arr[1001];
int main()
{
	int n,j,i;
	cin>>n>>j;
	for(i=0;i<=n;i++)
	{
		if(arr[i+1]==0||arr[i+1]>arr[i]+1)
			arr[i+1]=arr[i]+1;
		if(arr[i+j]==0||arr[i+j]>arr[i]+1)
			arr[i+j]=arr[i]+1;
	}
	cout<<arr[n];
	return 0;
}

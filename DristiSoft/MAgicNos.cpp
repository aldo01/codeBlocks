#include<bits/stdc++.h>
using namespace std;
int currsize=26;
queue <string> S1;
string S2;
void bfs()
{
	while(currsize<=10000)
	{
		string temp=S1.front();
		S1.pop();
		for(int c=65;c<=90;++c)
		{
			string x=string(1,c);
			string newstr=temp+x;
			int len=newstr.length();
			currsize+=len;
			S2+=newstr;
			S1.push(newstr);
		}
	}
}
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios::sync_with_stdio(false);
	for(int c=65;c<=90;++c)
	{
		S1.push(string(1,c));
	}
	for(int c=65;c<=90;++c)
	{
		S2+=string(1,c);
	}
	bfs();
	int index;
	for(int i=0;i<5;++i)
	{

	cin>>index;
	cout<<S2[index-1]<<"\n";
	}
	return 0;
}

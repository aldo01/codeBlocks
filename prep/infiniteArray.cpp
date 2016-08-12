#include<stdio.h>
#include<iostream>
using namespace std;
int main(int argc, char *argv[])
{
int k= 0;

while(1)
{
int input;
// Scan stream of 0 and 1
cin>>input;
if (input) k = k*2 +1;
else k = k*2;

k = k%3;
if (k == 0 )
cout<<"Yes"<<endl;
else
cout<<"No"<<endl;
}
	return 0;
}

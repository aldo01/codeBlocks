#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t,n,a,b,i;
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b;
        if(b<a){
            int temp=a;
            a=b;
            b=temp;

        }
        //cout<<a<<" "<<b<<endl;
        if(a==b)
        {
            cout<<(n-1)*a<<endl;

        }
        else
        {
            for(i=0;i<=n-1;i++)
            {
                cout<<(n-1-i)*a+(i)*b<<" ";

            }
        cout<<endl;
        }
    }
    return 0;
}

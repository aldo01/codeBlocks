#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define max 1000
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int l,i,j,num[max],min=1000,count=0;
    cin>>l;
    for(i=0;i<l;i++){
        cin>>num[i];
        if(num[i]<min)
            min=num[i];
    }
    sort(num,num+l);
    for(j=0;j<l;j++)
    {
        count=0;
        if(num[l-1]==0)
            break;
        for(i=0;i<l;i++){
            if(num[i]>=min){
                num[i]-=min;
                count++;
            }
        }
        cout<<count<<endl;
        min=1000;
        for(i=0;i<l;i++){
            if(num[i]!=0 & num[i]<min)
                min=num[i];
        }
    }
    return 0;
}


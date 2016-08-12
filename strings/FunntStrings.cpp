#include <stdio.h>

#include <string.h>

#include <math.h>

#include <stdlib.h>

int main() {

    int T,i,j,flag=0;
    char s[10000];
    scanf("%d",&T);
    while(T--)
        {
        scanf("%s",s);
        i=0;j=strlen(s) -1;
        flag = 0;
        for(;i<=j;)
            {
            if(abs(s[i]-s[i+1]) != abs(s[j]-s[j-1]))
                {
                flag    =   1;
                break;
            }
            i+=2;j-=2;
        }
        if(flag==1)
            printf("Not Funny\n");
        else
            printf("Funny\n");
    }
    return 0;
}

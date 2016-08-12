#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
   signed long long int sum=0;

   signed long long int arr[10];
    int t;
    int size= sizeof(arr)/sizeof(arr[0]);
    scanf("%lld",&t);
    for(int i=0;i<t;++i){
        scanf("%lld",&arr[i]);
        sum=sum+arr[i];
    }
    printf("%lld",sum);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}


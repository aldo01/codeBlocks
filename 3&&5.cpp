#include<stdio.h>




int main(){
     int t,n,k;
     int sum=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(k=1;k<n;k++){
            if(k%3==0 || k%5==0){
                sum=sum+k;
                printf("%d",sum);
            }
        }
       // sum=0;
    }
       return 0;
}


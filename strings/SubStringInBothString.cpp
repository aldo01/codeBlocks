#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 100000
int minlen(char[] ,char[]);
int maxlen(char[],char[]);

int main() {
    int i,j,k,l,t;
    char str1[MAX];
    char str2[MAX];
    scanf("%d",&t);
    while(t--){
         scanf("%s",&str1);
        scanf("%s",&str2);

        int j=minlen(str1,str2);
        int k=maxlen(str1,str2);
        for(i=0;i<j;i++){
            for(l=0;j<k;l++){
                if(str1[i]==str2[l])
                     printf("YES");
                else
                    printf("NO");
            }
        }


    }



    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
int maxlen(char str1[],char str2[]){
    if(strlen(str1)>strlen(str2))
        return strlen(str1);
    return strlen(str2);

}
 int minlen(char str1[],char str2[]){
     if(strlen(str1)<strlen(str2))
         return strlen(str1);
     return strlen(str2);
 }

#include<stdio.h>
#include<stdlib.h>
#define MAX 40


int countTrees(int num)
{
if(num<=1)
return 1;
else
{
int root,left,right,sum=0;
for(root=1;root<=num;root++)
{
left=countTrees(root-1);
right=countTrees(num-root);
sum+=left*right;
}
return sum;
}
}

int main(){
 int num,i;
 int t;
 int arr[MAX];
 scanf("%d",&t);
 while(t--){
 // for(i=0;i<=t;i++)
  scanf("%d",&num);


  for(i=0;i<=t;i++)
  printf("%d\n",countTrees(num));
}
}

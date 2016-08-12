#include "stdio.h"
#include "string.h"
#include<map>
#include<stdlib.h>
using namespace std;


typedef map<int,char*>List;
void foo()
{

List I;
FILE * f=fopen("/home/nimish/readme.txt","r");

if(f)
{
char line[100];

for(int i=0;fgets(line,sizeof(line),f);i++){
I[i]=new char[strlen(line)];
strcpy(I[i],line);
}
}

for(List::const_iterator it=I.begin();it!=I.end();++it){
printf("%d %s",it->first,it->second);
}
}
int main()
{

foo();
return 1;
}

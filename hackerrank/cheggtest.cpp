
#include<stdio.h>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;


int main(){
   string str="The chegg welcome you to the new world say hi!Chegg";
int pos1=str.find("welcome");
int pos2=str.find("Chegg");
int pos3=str.find("Chegg",pos2+1);
int pos4=str.find("hi");
int pos5=str.find("to");
int pos6=str.find("you");
int pos7=str.find("say");
string newStr=str.substr(pos3,5);
newStr+=str.substr(pos1,7);
newStr=str.substr(pos6,3);
newStr=str.substr(pos2,5);
newStr+=" "+str.substr(pos1,7);
newStr+=str.substr(pos7,1);
newStr+=" "+str.substr(pos6,3);
newStr=str.substr(pos4,3)+newStr;
//printf("%s",newStr);
cout << newStr << " " <<endl;


 return 0;



}


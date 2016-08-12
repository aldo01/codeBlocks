#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int *foo(){
 int a=5;
 return &a;
}

int main(){
 int *p=foo();
 cout<<*p;
 *p=8;
 cout<<*p;
}

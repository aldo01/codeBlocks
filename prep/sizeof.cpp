#include<stdio.h>

#define my-sizeof(type)(char*)(&type+1)-(char*)(&type)

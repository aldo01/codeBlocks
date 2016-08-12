
#include <iostream>
using namespace std;
int mat[5][5]={{1,2,3,4,5},
{6,7,8,9,10},
{11,12,13,14,15},
{16,17,18,19,20},
{21,22,23,24,25}};

int main() {
int x,y,row,col;
cin>>x;
if(1<=x&&x<=5){
row=0;
}else if(6<=x&&x<=10){
row=1;
}else if(11<=x&&x<=15){
row=2;
}else if(16<=x&&x<=20){
row=3;
}else if(21<=x&&x<=25){
row=4;
}
cin>>y;
if(1<=y && y<=5){
col=0;
}else if(6<=y && y<=10){
col=1;
}else if(11<=y&&y<=15){
col=2;
}else if(16<=y&&y<=20){
col=3;
}else if(21<=y&&y<=25){
col=4;
}
//cout<<row<<" "<<col<<"\n";
if(row==col){
while(x<=y){
cout<<x<<" ";
x++;
}
}else if(row<col){
while(row<=col){
cout<<x<<" ";
x+=5;
row++;
}
x-=5;
if(x!=y){
if(x>y){
while(x>=y){
x--;
if(x<y)
break;
cout<<x<<" ";
}
}else{
while(x<=y){
x++;
if(x>y)
break;
cout<<x<<" ";
}
}
}
}


return 0;
}

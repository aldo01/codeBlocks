#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

int main(){

  int N = 5;

    //  B - Blank     O - Obstacle
    string mat[N] = {"BBOBB",
                     "BBBBO",
                     "BBBBB",
                     "BOOBO",
                     "BBBOB"
                    };

    cout << maximumMirrorInMatrix(mat, N) << endl;

    return 0;

}


int maximumMirrorInMatrix(string mat [], int n){

  int horizontal[n];
  int vertical[n];

  memset(horizontal,-1,sizeof(horizontal));
  memset(vertical, -1, sizeof(vertical));




}

#include <stdio.h>
#define N 1001

int visited[N][N];
int room[N][N];
//int dx[]={1, 0, 0, -1} , dy[]={-1, 0, 0, 1};//for all neighbours
int dx[]={0, -1, 0, 1}, dy[]={-1, 0, 1, 0};
int noOfRoom;
int store[N][N];

int calculate(int row, int col)
{
  int max = 0, k; //k is used for the 4 directions

  for(k=0;k<4;k++)
  {
    //if( (room[row][col]+1==room[row+dx[k]][col+dy[k]]) && !(row+dx[k]>=noOfRoom || row+dx[k]<0 || col+dy[k]<0 || col+dy[k]>=noOfRoom)) //checking condition
    if(!(row+dx[k]>=noOfRoom || row+dx[k]<0 || col+dy[k]<0 || col+dy[k]>=noOfRoom))
    {if( (room[row][col]+1==room[row+dx[k]][col+dy[k]]))
      {

      int a = calculate(row+dx[k], col+dy[k]);
      max = a > max ? a : max;

      }
    }
  }
   max=max+1;
  store[row][col] = max;

  return store[row][col];

}

int main()
{

  int row, col, ans = 0, val = 1001;

  scanf("%d", &noOfRoom);
  for(row=0;row<noOfRoom;row++)
  {
    for(col=0;col<noOfRoom;col++)
    {
      scanf("%d", &room[row][col]);

    }
  }

  for(row=0;row<noOfRoom;row++)
    for(col=0;col<noOfRoom;col++)
      visited[row][col] = 0;

  int max = 0; int last=room[0][0];
  for(row=0;row<noOfRoom;row++)
  {

    for(col=0;col<noOfRoom;col++)

    {
      max = calculate(row,col);

      if(ans<max)
      {
          ans=max;
          val=room[row][col];
          last=val;
      }
      if(ans==max)
      {
         if(room[row][col]<last)
         {  val=room[row][col];
         }

      }

    }
  }

  printf("Room : %d , Length : %d", val, ans);
  return 0;
}

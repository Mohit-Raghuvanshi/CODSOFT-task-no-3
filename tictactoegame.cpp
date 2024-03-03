#include<iostream>
using namespace std;
void createboard(char board[3][3])
{
    cout<<"____________\n\n";
    for(int i=0;i<3;i++)
    {
        cout<<"| ";
        for(int j=0;j<3;j++)
        {
            cout<<board[i][j]<<" | ";
        }
        cout<<"\n____________\n\n";
    }
}
int winner(char board[3][3],char player)
{
  for(int i=0;i<3;i++)
  {
    int count=0;
    for(int j=0;j<3;j++)
    {
        if(board[i][j]==player)
        {
            count++;
        }
    }
    if(count==3)
    {
        return 1;
    }
  }
  for(int i=0;i<3;i++)
  {
    int count=0;
    for(int j=0;j<3;j++)
    {
        if(board[j][i]==player)
        {
            count++;
        }
    }
    if(count==3)
    {
        return 1;
    }
  }
  if(board[0][0]==player&&board[1][1]==player&&board[2][2]==player)
  {
    return 1;
  }
   if(board[2][0]==player&&board[1][1]==player&&board[0][2]==player)
  {
    return 1;
  }
  return 0;
}
int main()
{
    int n;
     do
     {
    char board[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    char player='O';
    int x,y;
    int chances;
        cout<<"\nwelcome to tic-tac-toe game\n";
    for( chances=0;chances<9;chances++)
    {
      createboard(board);
      while(1)
      {
      cout<<"\nPlayer "<<player<<" enter row(0-2) and column(0-2)\n";
      cin>>x>>y;
      if(board[x][y]!=' '||x<0||x>2||y<0||y>2)
      {
        cout<<"\nInvalid move\nTry again!\n";
      }
      else
      {
        break;
      }
      }
      board[x][y]=player;
      if(winner(board,player))
      {
        cout<<"\nplayer "<<player<<" wins\n";
        createboard(board);
        break;
      }
      else
      {
        if(chances%2==0)
        {
          player='X';
        }
        else
        player='O';
      }
    }
    if(chances==9)
    {
      createboard(board);
      cout<<"\nDraw";
    }
    while(1)
    {
    cout<<"\n1.Play again\n2.Exit\n";
    cin>>n;
    if(n==1||n==2)
    {
         break;
    }
    else
     cout<<"\nInvalid choice";
    }

}while(n!=2);
    return 0;
}
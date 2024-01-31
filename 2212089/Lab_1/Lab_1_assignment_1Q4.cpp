#include<iostream>
using namespace std;
/*(Tic-Tac-Toe) Write a program that allows two players to play the tic-tac-toe game.
Your program must contain the class ticTacToe to implement a ticTacToe object.
Include a 3-by-3 two-dimensional array, as a private member variable, to create the
board. If needed, include additional member variables. Some of the operations on a
ticTacToe object are printing the current board, getting a move, checking if a move
is valid, and determining the winner after each move. Add additional operations as
needed*/
class TicTacToe{
    char board[3][3];

    public:
       // lets create a constructor//
       TicTacToe()
       {
             for(int i=0;i<3;i++)
            {
              for(int j=0;j<3;j++)
                  {
                      board[i][j]=' ';
                  }
            }
        }
        //lets now frame a tictactoe board//
        void printBoard()
        {
        
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    cout<<board[i][j];
                    if(j<2)
                    {
                        cout<<"|";
                    }
                }
                cout<<"\n";
                if(i<2)
                {
                    cout<<"------\n";
                }
            }
        }
    bool checkifvalidmove(int row,int column)
  {
    return row>=0 && row<3 && column>=0 && column<3 && board[row][column]==' ';
   }
   bool makeMove(int row,int column,char symbol)
  {
    if(checkifvalidmove(row,column))
    {
        board[row][column]=symbol;
        return true;
    }
    return false;
  }
  //function to make winner//
  bool isWinner(char symbol)
  {
    if(board[0][0]==symbol && board[1][1]==symbol && board[2][2]==symbol)
    {
        return true;
    }
    if(board[0][2]==symbol && board[1][1]==symbol && board[2][0]==symbol)
    {
        return true;
    }
    for(int i=0;i<3;i++)
    {
      if(board[i][0]==symbol && board[i][1]==symbol && board[i][2]==symbol)
      {
        return true;
      }
      if(board[0][i]==symbol && board[1][i]==symbol && board[2][i]==symbol)
      {
        return true;
      }
    }
    return false;
    }
};
// lets now create our main function//
int main()
{
    //lets create an object of our class//
    TicTacToe game;
    cout<<"WELCOME TO TIC-TAC-TOE\n";
    //game is our object//
    char player_A='X';
    char player_B='O';
    char current_player=player_A;
    while (true)
    {
        game.printBoard();
        int row;
        int column;
        cout<<"Player "<<current_player<<": Enter row and column: \n";
        cin>>row>>column;
        if(game.makeMove(row,column,current_player))
        {
            if(game.isWinner(current_player))
            {
                cout<<"Player "<<current_player<<"is the Winner\n";
                cout<<"Congratulations";
                break;
            }
            if(current_player==player_A)
            {
                current_player=player_B;
            }
            else{
                current_player=player_A;
            }
        }
        else{
            cout<<"Invalid move,Try another move";
        }
    }
    return 0;
}

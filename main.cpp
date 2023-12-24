#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

void initializeBoard(char board[][COLS]){

  for (int i = 0; i < ROWS; i++)
    for(int j = 0; j < COLS; j++)
      board[i][j] = '*';
  
}

void printBoard(char board[][COLS]){
  cout << endl;
   for (int i = 0; i < ROWS; i++){
     for(int j = 0; j < COLS; j++)
       cout << board[i][j] << " ";
     cout << endl;
   }
  cout << endl;
}

bool gameIsWon(char board[][COLS]){

   return ((board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] != '*') ||
    (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] != '*') ||
    (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] != '*') ||
    
    (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] != '*') ||
    (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] != '*') ||
    (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] != '*') ||
    
    (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '*') ||
    (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '*'));
    
}

int main() {
  int row, col, moves = 0;
  char player = 'X';
  char board[ROWS][COLS];
  initializeBoard(board);
  cout << "~~~Welcome To Tic-Tac-Toe~~~\n";

  do{
  printBoard(board);

  cout << "~~~Player " << player << "'s turn~~~\n";
  cout << "Please enter row: ";
  cin >> row;
  cout << "Please enter col: ";
  cin >> col;
  
  row--; col--;
  if(board[row][col] == '*'){
    board[row][col] = player;
    if(gameIsWon(board)){
      printBoard(board);
      cout << "Player " << player << " Wins!!\n";
      exit(EXIT_SUCCESS);
    }
    moves++;
  } else
      cout << "Space Occupied! Player " << player << " loses turn.\n";

  if(player == 'X')
    player = '0';
  else
    player = 'X';
  } while(moves <= 9);
  printBoard(board);
  cout << "It' a DRAW :(\n";
}
#include <iostream>
#include <iomanip>

using namespace std;

int main () {
  int moves, result = 0; 
  cin >> moves; 
  
  int listMoves[moves];
  for (int i = 0; i < moves; i++) cin >> listMoves[i];

  /**Chessboard**/
	int board[8][8] = {0}; 
  
  /** Black holes **/
	board[2][2] = 1;
  board[3][5] = 1;
  board[4][1] = 1;
  board[4][2] = 1;

  int x = 4, y = 4, i = 0; 
  while(moves--) {
    
    int a, b;
    switch (listMoves[i]) {
      case 1:
        a = x + 1;
        b = y + 2;
        board[a][b];
        break;

      case 2:
        a = x + 2;
        b = y + 1;
        board[a][b];
        break;

      case 3:
        a = x + 2;
        b = y - 1;
        board[a][b];
        break;

      case 4:
        a = x + 1;
        b = y - 2;  
        board[a][b];
        break;

      case 5:
        a = x - 1;
        b = y - 2; 
        board[a][b];
        break;

      case 6:
        a = x - 2;
        b = y - 1;
        board[a][b];
        break;

      case 7:
        a = x - 2;
        b = y + 1;
        board[a][b];
        break;

      case 8:
        a = x - 1;
        b = y + 2;
        board[a][b];
        break;          

    default:
      cout << "Input not valid";
      break;
    };
    
    cout << board[a][b] << ' ' << a << ' ' << b << endl; 
    if (board[a][b] != 1 && board[a][b] != 0) {
      cout << "entrei"; 
      i += 1;
      continue;
    };

    if (board[a][b] == -1) {
      result += 1;
      break;
    };

    x = a;
    y = b;
    result += 1;
    i += 1;
  }

  // for (int i = 0; i < 8; i++) {
  //   for (int j = 0; j < 8; j++) {
  //     cout << board[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  cout << result; 
	return 0; 
}
//5
//1 8 2 5 3
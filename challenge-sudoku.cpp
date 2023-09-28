#include <iostream>
using namespace std;
const int size = 9;
int main() {
  int N, test = 0;
  cin >> N;
  while (N--) {
    int board[size][size] = {};
    for (int x = 0; x < size; x++) for (int y = 0; y < size; y++) cin >> board[x][y];

    bool sudoku = true;
    for (int i = 0; i < 9; i++) {
      int curr = i+1;
      int j, k;
      bool rowCheck[9] = {};
      bool colCheck[9] = {};
      for (j = 0; j < 9; j++ ) {
        int qtyInRow = 0;
        int qtyInCol = 0;

        for (k=0+j; k < 9; k++) {
          if (rowCheck[j] == true && colCheck[j] == true) continue;
          if (board[j][k] == curr) {
            qtyInRow += 1;
            rowCheck[j] = true;
            colCheck[k] = true;
          };
          if (board[k][j] == curr) {
            qtyInCol += 1;
            colCheck[j] = true;
            rowCheck[k] = true;
          };
        };
        // if (qtyInRow == 1 || qtyInRow == 0 && rowCheck[j] == true) ok;
        // if (qtyInCol == 1 || qtyInCol == 0 && colCheck[j] == true)
          if (
            qtyInRow > 1 || qtyInCol > 1 ||
            qtyInRow == 0 && rowCheck[j] == false ||
            qtyInCol == 0 && colCheck[j] == false
          ) {
            sudoku = false;
            break;
          };
      };
    };
    end:
    test++;
    if (sudoku) cout << "Instancia " << test << endl << "SIM" << endl << endl;
    else cout << "Instancia " << test << endl << "NAO" << endl << endl; 
  };

  return 0;
};

/* 

        int row = matrix[j][i];
        int col = matrix[i][j];

curr = 1
getrow curr != ncol ? get 
getcol curr != nrow ? get row  and col 
Sim ? x y


row[0] && col[0] != V ? 
curr 1 == l ? qty++ { }
curr 1 == c ? qty++ {}

qty > 1 ? goto end;


row     col          
0 F     0 F       
1 F     1 F    
2 F     2 F   
3 F     3 F   
4 F     4 F   
5 F     5 F   
6 F     6 F    
7 F     7 F   
8 F     8 F   

V 3 2 | 5 7 9 | 4 6 8
4 9 8 | 2 6 V | 3 7 5
7 5 6 | 3 8 4 | 2 V 9
------+-------+------
6 4 3 | V 5 8 | 7 9 2
5 2 V | 7 9 3 | 8 4 6
9 8 7 | 4 2 6 | 5 3 V
------+-------+------
2 v 4 | 9 3 5 | 6 8 7
3 6 5 | 8 V 7 | 9 2 4
8 7 9 | 6 4 2 | V 5 3




  int arr[9][9] = {
    {1, 3, 2, 5, 7, 9, 4, 6, 8},
    {4, 9, 8, 2, 6, 1, 3, 7, 5},
    {7, 5, 6, 3, 8, 4, 2, 1, 9},
    {6, 4, 3, 1, 5, 8, 7, 9, 2},
    {5, 2, 1, 7, 9, 3, 8, 4, 6},
    {9, 8, 7, 4, 2, 6, 5, 3, 1},
    {2, 1, 4, 9, 3, 5, 6, 8, 7},
    {3, 6, 5, 8, 1, 7, 9, 2, 4},
    {8, 7, 9, 6, 4, 2, 1, 5, 3}
  };



*/
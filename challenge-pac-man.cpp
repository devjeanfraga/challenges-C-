#include <iostream>
using namespace std;

int main() {
  // Escreva seu código aqui
  int boardSize, maxFood = 0, qtyFood = 0; 
  cin >> boardSize; 

  // declarar e inicializar tabuleiro; 
  char board[boardSize][boardSize] = {};
  for (int x = 0; x < boardSize; x++) for (int y = 0; y < boardSize; y++)  cin >> board[x][y];

  int line = 0;

  // percorrer tabuleiro da esquerda para a direita e vice-versa;
  while (boardSize--) {
    int col, 
        size = sizeof(board[line])/sizeof(char);

    // verificar a direção a ser percorrida
    bool isLefToRight = line%2 == 0;
    isLefToRight ? col = 0 : col = size-1;

    // incrementar o máximo de comida possível;
    while (size--) {
      if (board[line][col] == 'o') {
        qtyFood += 1;
        if ( qtyFood > maxFood )  maxFood = qtyFood;
      };
      if (board[line][col] == 'A') qtyFood = 0;
    
      isLefToRight ? col += 1 : col -= 1;
    };
    line += 1;
  };
  cout << maxFood; 
  return 0;
};
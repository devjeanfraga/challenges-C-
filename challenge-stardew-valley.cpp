#include <iostream>
using namespace std;


int main() {
  // Escreva seu c�digo aqui
  int qtyRow, qtyCol, sum = 0;
  cin >> qtyRow >> qtyCol;

  int **plantation;
  plantation = new int* [qtyRow];
  for (int i = 0; i < qtyRow; i++ ) plantation[i] = new int [qtyCol];

  for (int x = 0; x < qtyRow; x++ ) for (int y = 0; y < qtyCol; y++) cin >> plantation[x][y];

  char direction;
  int id;
  cin >> direction >> id;
  id -= 1;
  if (direction == 'C') for (int i = 0; i < qtyRow; i++) sum += plantation[i][id];
  if (direction == 'L') for (int j = 0; j < qtyCol; j++) sum += plantation[id][j];
  
  for (int i = 0; i < qtyRow; i++ ) delete [] plantation[i];
  delete [] plantation;
  cout << sum;
  return 0;
};

#include <iostream>
using namespace std;


int main() {
  // Escreva seu c�digo aqui
  int X, Y, sum = 0;
  cin >> X >> Y;

  int plantation[X][Y] = {};
  for (int l = 0;l < X; l++ ) for (int c = 0; c < Y; c++) cin >> plantation[l][c];

  char direction;
  int id;
  cin >> direction >> id;
  id = id -1;
  if (direction == 'C') for (int i = 0; i < X; i++) sum += plantation[i][id];
  if (direction == 'L') for (int j = 0; j < X; j++) sum += plantation[id][j];
  
  cout << sum;
  return 0;
};

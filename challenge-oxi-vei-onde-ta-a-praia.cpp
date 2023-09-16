#include <iostream>
using namespace std;
const int size = 10; 
bool isThereABeach (int x, int y, char arr[][size]) {
  return (x >= 0 && x < size && y >= 0 && y < size) && arr[x][y] == '*'; 
};
int main() {
  char map[size][size] = {};
  // leitura das entradas;
  for (int x = 0; x < size; x++) for (int y = 0; y < size; y++) cin >>  map[x][y]; 
  
  for (int row = 0; row < size; row++) for (int col = 0; col < size; col++) {
    if (map[row][col] == '*') continue;
    
    if (
        (isThereABeach(row+1, col, map)) ||  // down   
        (isThereABeach(row-1, col, map)) ||  // up
        (isThereABeach(row, col+1, map)) ||  // rigth
        (isThereABeach(row, col-1, map))     // left
    ) map[row][col] = 'p';
  };

  // Imprimir mapa com praia;
  cout << endl;
  for (int x = 0; x < size; x++) {
    for (int y = 0; y < size; y++) cout << map[x][y] << ' '; 
    cout << endl;
  };
  return 0;
};

/*
* * * * * * * * * *
* * p p p p * * * *
* p p p t t p * * *
* * * * p t t p p *
* * * * * p t t p *
* * * * * p t p * *
* * * * p t t p * *
p p p p t t t t p *
t t t t t p p p * *
t t t t p * * * * *

    if (
        (isWithinTheBounds(row+1, col) && map[row+1][col] == '*') || // down   
        (isWithinTheBounds(row-1, col) && map[row-1][col] == '*') || // up
        (isWithinTheBounds(row, col+1) && map[row][col+1] == '*') || // rigth
        (isWithinTheBounds(row, col-1) && map[row][col-1] == '*') // left
    ) map[row][col] = 'p';

*/

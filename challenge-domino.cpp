#include <iostream>
using namespace std;
const int size = 7;
int main() {
  // Escreva seu código aqui
  int grid[size][size] = {}, result = 0;

  for (int x= 0; x < size; x++) for (int y = 0; y < size; y++) cin >> grid[x][y];
  
  for (int x= 0; x < size; x++) for (int y = 0; y < size; y++) {
    if (grid[x][y] == 1 && grid[y][x] == 1) {
      result += 1;
      grid[y][x] = 0;
    };
  }

  cout << result;
  return 0;
}
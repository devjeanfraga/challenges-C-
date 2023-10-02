#include <iostream>
using namespace std;
const int size = 8;

bool isValidBound(int x, int y) {
  return (x >= 0 && x < size) && (y >= 0 && y < size); 
};

int main() {
  int qty = 0, x, y;
  int grid[size][size] = {};
  for (int row = 0; row < size; row++) for (int col = 0; col < size; col++) cin >> grid[row][col];
  cin >> x >> y;

  // up
  int i = 1;
  while ( x-i >= 0 ) {
    if (grid[x-i][y] == 1) break;
    if (grid[x-i][y] == 2) {
      qty += 1;
      break;
    };
    i++;
  };

  //down
  i = 1;
  while (x+i < size) {
    if (grid[x+i][y] == 1) break;
    if (grid[x+i][y] == 2) {
      qty += 1;
      break;
    };
    i++;
  };

  // right
  i = 1;
  while (y+i < size) {
    if (grid[x][y+i] == 1) break;
    if (grid[x][y+i] == 2) {
      qty += 1;
      break;
    };
    i++;
  };

  //left
  i = 1;
  while (y-i >= 0) {
    if (grid[x][y-i] == 1) break;
    if (grid[x][y-i] == 2) {
      qty += 1;
      break;
    };
    i++;
  };

  cout << qty;
  return 0;
};

/*
  int i = 1;








*/
#include <iostream>
using namespace std;

bool isACoastline (char* arr, int x, int y, int qtyRow, int qtyCol) {
  bool isWithinTheBounds = (x >= 0 && x < qtyRow && y >= 0 && y < qtyCol);
  bool isWater = ( *( (arr+x*qtyCol) + y ) == '.');
  return  !isWithinTheBounds || (isWithinTheBounds && isWater);    
};
int main() {
  int row, col, total = 0;
  cin >> row >> col;
  char map[row][col] = {};
  // leitura das entradas;
  for (int x = 0; x < row; x++) for (int y = 0; y < col; y++) cin >>  map[x][y]; 
  
  for (int x = 0; x < row; x++) for (int y = 0; y < col; y++) {
    if (map[x][y] == '.') continue;
    if (
        (isACoastline((char*)map, x+1, y, row, col)) ||  // down   
        (isACoastline((char*)map, x-1, y, row, col)) ||  // up
        (isACoastline((char*)map, x, y+1, row, col)) ||  // rigth
        (isACoastline((char*)map, x, y-1, row, col))     // left
    ) total += 1;
  };

  cout << total;
  return 0;
};


#include <iostream>
#include <iostream>

using namespace std;
int main() {
  int x, y;
  cin >> x >> y;

  int grid[x][y] = {};
  for (int i = 0; i < x; i++) for (int j = 0; j < y; j++) cin >> grid[i][j];

  int greaterX = 0; 
  for (int i = 0; i < x; i++) {
    int currentX = 0;
    for (int j = 0; j < y; j++) currentX += grid[i][j];
    if (currentX > greaterX) greaterX = currentX;
  }

  int greaterY = 0;
  for (int i = 0; i < y; i++) {
    int currentY = 0;
    for (int j = 0; j < x; j++) currentY += grid[j][i];
    if (currentY > greaterY) greaterY = currentY;
  }

  cout << (greaterX > greaterY ? greaterX : greaterY);
  return 0;
}
#include <iostream>
using namespace std;

int main() {
  int N, total = 0;
  cin >> N;
  int area[N][N] = {};
  // leitura de area;
  for (int x = 0; x < N; x++) for (int y = 0; y < N; y++) cin >>  area[x][y]; 
  
  int qtyCoordinates, x, y;
  cin >> qtyCoordinates;
  while (qtyCoordinates-- && cin >> x >> y ) total += area[x][y];

  cout << total;
  return 0;
};

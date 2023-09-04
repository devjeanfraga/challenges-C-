#include <iostream>
using namespace std;

int main() {
  // Escreva seu código aqui
  int N, T;
  cin >> N >> T;
  int grid[N][N] = {};
  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> grid[i][j];

  int L, C, sum = 0;
  while (T--) { 
    cin >> L >> C;
    bool isDowned = false;
    
    if (L == 0 ) continue;
    else while (L > 0) {
      L -= 1;
      if (grid[L][C] == 1) {
        grid[L][C] = 0;
        isDowned = true;
        break;
      };
    }
    if (isDowned) sum += 1;
  };
  cout << sum;
  return 0;
}
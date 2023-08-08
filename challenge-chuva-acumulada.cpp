#include <iostream>
#include <iostream>

using namespace std;
int main() {
  int N;
  cin >> N;

  int periodA[N][N] = {};
  int periodB[N][N] = {};

  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> periodA[i][j];
  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> periodB[i][j];
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) cout << periodA[i][j] + periodB[i][j] << ' ';
    cout << endl;
  };
  return 0;
}
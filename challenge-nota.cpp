#include <iostream>
using namespace std;

int main() {
  int N, result;
  int values[101] = {};

  cin >> N;
  int scores[N] = {};
  for (int i = 0; i < N && (N < 200); i++ ) cin >> scores[i];

  for (int i = 0; i < N; i++ ) values[scores[i]] += 1; 
  
  int greater = 0;
  for (int i = 0; i < 101; i++ ) { 
    if(values[i] >= greater) {
      greater = values[i];
      result = i;
    }
  }
  cout << result;
  return 0;
}

/*
  0 1 2 3 4 5 
  0 1 2 2 3 0

  4 3 2 4 2 1 3 4

return maior
*/
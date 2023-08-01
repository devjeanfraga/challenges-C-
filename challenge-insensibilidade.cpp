#include <iostream>
using namespace std; 

int main () {
  int N, result = 0; 
  cin >> N;

  int X[2] = {};
  int Y[2] = {};

  while(N--) {
    cin >> X[0] >> X[1] >> Y[0] >> Y[1];
    int square1 = (X[0] - Y[0]) * (X[0] - Y[0]);
    int square2 = (X[1] - Y[1]) * (X[1] - Y[1]);
    result += (square1 + square2);
  }

  cout << result; 
  return 0;
}


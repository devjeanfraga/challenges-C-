#include <iostream>
using namespace std;

int main() {
  // Escreva seu código aqui
  int tourists[4] = {},
      total = 0;

  for (int i = 0; i < 4; i++) {
    cin >> tourists[i];
    total += tourists[i]-2;
  };
  
  cout << total;

  return 0;
}
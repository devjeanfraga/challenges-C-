#include <iostream>
using namespace std;

int main() {
  // Escreva seu código aqui
  int totalHunt[3] = {},
      egges[3] = {},
      total = 0;

  for (int i = 0; i < 3; i++) {
    cin >> totalHunt[i];
    total += totalHunt[i];
  };

  for (int i = 0; i < 3; i++) {
    cin >> egges[i];
    total -= egges[i]*3;
  };
  
  cout << total;

  return 0;
}
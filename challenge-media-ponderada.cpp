#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  float avaliacoes[3] {};
  cin >> avaliacoes[0] >> avaliacoes[1] >> avaliacoes[2];
  float media = (
        (avaliacoes[0] * 4) + 
        (avaliacoes[1] * 4) + 
        (avaliacoes[2] * 2)
        ) / 10;
  cout << setprecision(2) << fixed << media;
  return 0;
} 

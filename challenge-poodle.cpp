#include <iostream>
using namespace std;

int main() {
  // Escreva seu código aqui
  int N, P;
  const int wordSize = 6; 

  while (cin >> N >> P ) {
    string numberOfLetter = ""; 
    int numberOfPages = (N % P > 0 ? 1 : 0) + (N / P) - 6;
    if (numberOfPages > 0 ) for (int i = 0; i <= numberOfPages && i < 14; i++) numberOfLetter = numberOfLetter + 'o';
    cout << "Poo" + numberOfLetter  + "dle";
  };
  return 0;
}
#include <iostream>
using namespace std;

int main() {
  // Escreva seu código aqui
  int value, rest, qtyI, qtyJ, qtyK, qtyL, test = 1;
  while ( cin >> value && value != 0 ) {
    qtyI = value/50;
    rest = value%50;
    qtyJ= rest/10;
    rest = rest%10;
    qtyK = rest/5;
    rest = rest%5;
    qtyL = rest/1;
    rest = rest%1;  

    cout << "Teste " << test++ << endl; 
    cout << qtyI << ' ' << qtyJ << ' ' << qtyK << ' ' << qtyL << endl;
    cout << endl;
  }; 
  return 0;
};
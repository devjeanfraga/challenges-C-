#include <iostream>
#include <cmath>
using namespace std;

int main() {
  // Escreva seu código aqui
  int N, qtyBacterias, days, type; 
  long double greater = 0, current;
  cin >>  N;
  for ( int i = 0; i < N; i++ ) {
    cin >> qtyBacterias >> days;
    current = pow(qtyBacterias, days/1000);
    if ( current > greater ) {
      greater = current;
      type = i; 
    };
  };
  cout << type;
  return 0;
}
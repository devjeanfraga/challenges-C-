#include <iostream>
#include <cmath>
using namespace std;


int Hanoi( int N, int counter) {
  int result;
  if ( counter == 1) return 2;
  else {
    counter -= 1;
    return 2 * Hanoi(N, counter);
  }
}

int TabulationHanoi (int N) {
  int tab[N] = {};
  tab[0] = 2;
  if (N == 1) return 2;
  else {
    for (int i = 1; i < N; i++) {
      tab[i] = tab[i-1] * 2;
    };
  }
  return tab[N-1]; 
}

int main() {
  // Escreva seu código aqui
  int result, N, test = 1;
  while ( cin >> N && N ) {
    result =  TabulationHanoi(N);  //Hanoi(N, N);
    cout << "Teste " << (test++) << endl;
    cout << result-1 << endl; 
    cout << endl;
  };
  return 0;
}
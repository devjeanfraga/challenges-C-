#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int rumoAos9s ( string input, int deep = 0);
int main() {
  string N;
  while ( cin >> N && N != "0" ) {
    int grau = rumoAos9s(N);
    if ( grau != 0 ) cout << N << " is a multiple of 9 and has 9-degree " << grau << '.' << endl;
    else cout << N << " is not a multiple of 9." << endl;
  };
  return 0;
}

int rumoAos9s (string input, int deep) {
  // soma
  int sum = 0;
  for (int i =0; i < input.length(); i++) sum += (input[i]-'0');
  
  // incrementa
  deep += 1;

  // condição de parada; 
  if (to_string(sum).length() == 1) {
    if ( sum%9 == 0) return deep;
    return 0; 
  }; 

  // recurso
  return rumoAos9s(to_string(sum), deep);
};

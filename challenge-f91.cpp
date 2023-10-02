#include <iostream>
using namespace std;

int f91(int N) {
  if (N >= 101) return N-10;
  else f91(N+(101-N));
};
int main() {
  // Escreva seu código aqui
  int n;
  while(cin >> n && n) cout << "f91(" << n << ") = " << f91(n) << endl;
  return 0;
}
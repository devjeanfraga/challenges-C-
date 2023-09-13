#include <iostream>
using namespace std;

int main() {
  // Escreva seu código aqui
  int attack, defense, qtyAttacks = 0;
  cin >> defense >> attack;

  while (attack > 0 && defense > 0 ) {
    defense -= attack;
    attack -= 1;
    qtyAttacks += 1;
  };

  if (defense <= 0) cout << qtyAttacks;
  else cout << 'F';

  return 0;
}
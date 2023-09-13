#include <iostream>
using namespace std;
const int size = 12;

int main() {
  // Escreva seu código aqui
  int orcs = 0, humans = 0;
  bool gotOrcWizard = false, gotHumanWizard = false;

  // inicialização do array dinamico;
  char** battlefield; 
  battlefield = new char* [size];
  for (int i = 0; i < size; i++) battlefield[i] = new char[size];

  // coleta de inputs e verificaçao de magos;
  for (int x = 1; x < size-1; x++) for (int y = 1; y < size-1; y++) {
    cin >> battlefield[x][y];
    if (battlefield[x][y] == 'm' && y <= 5) gotOrcWizard = true;
    if (battlefield[x][y] == 'm' && y >= 6) gotHumanWizard = true;
  };

  // somatorio de poderes de orcs humans;
  for (int row = 1; row <= 10; row++) for (int col = 1; col <= 10; col++) {
    char entity = col <= 5 ? 'o' : 'h';
    bool wizard = col <= 5 ? gotOrcWizard : gotHumanWizard;
    int qtyPower = 0;

    if ( battlefield[row][col] != '*') {
      if (wizard) { 
        if (battlefield[row][col-1] == entity || battlefield[row][col-1] == 'm') qtyPower += 1; // left
        if (battlefield[row-1][col] == entity || battlefield[row-1][col] == 'm') qtyPower += 1; // up
        if (battlefield[row][col+1] == entity || battlefield[row][col+1] == 'm') qtyPower += 1; // right
        if (battlefield[row+1][col] == entity || battlefield[row+1][col] == 'm') qtyPower += 1; // down
      };
      qtyPower += 1;
      col <= 5 ? orcs += qtyPower : humans += qtyPower;
    };
  };

  if (orcs == humans) cout << "Batalha lendaria! ";
  else if (orcs > humans) cout << "Loktar Ogar!!! ";
  else cout << "Pela Alianca! ";

  // liberação de memória; 
  for (int i = 0; i < size; i++) delete [] battlefield[i];
  delete [] battlefield;
  return 0;
};
#include <iostream>
using namespace std;

int main() {
  // Escreva seu código aqui
  // inicializar contadores e dimensoes da matriz
  int size = 10, orcs = 0, humans = 0;

  // inicializar booleanos para verificar a presença do mago;
  bool gotOrcWizard = false, gotHumanWizard = false;
  
  // inicializar matriz 
  char** battlefield; 
  battlefield = new char* [size];
  for (int i = 0; i < size; i++) battlefield[i] = new char[size];

  // popular matriz 
  for (int x = 0; x < size; x++) {
    for (int y = 0; y < size; y++) cin >> battlefield[x][y];
  };
  
  // percorrer matriz da col 0-4
  // verificar se existe mago no lado esquerdo;
  int start = 0;
  for (int row = 0; row < size; row++) {
    for (int col = start; col < size-5; col++) {
        if(battlefield[row][col] == 'm') {
          gotOrcWizard = true;
          break;
        }; 
      };
  };

  // percorrer matriz da col 5-9
  // verificar se existe mago no lado direito;
  start = 5;
  for (int row = 0; row < size; row++) {
    for (int col = start; col < size; col++) {
        if(battlefield[row][col] == 'm') {
          gotHumanWizard = true;
          break;
        }; 
      };
  };

  // declarar elemento e lados horizontais e verticais para os próximos loops;
  char el, left, right, up, down;

  // Orc Side; 
  // for aninhado percorre a matriz de 0-4;
  // se tiver mago soma os lados na horizontal e vertical
  // se nao tiver mago soma apenas o elemento diferente de '*'; 
  for (int row = 0; row < size; row++) {
    for (int col = 0; col < size-5; col++) {
        el = battlefield[row][col];
        if ( el != '*') {
          if (gotOrcWizard) {
            // ternário para não acessar lixo;
            left = col != 0 ? battlefield[row][col-1] : '0',
            right = col != size-5-1 ? battlefield[row][col+1] : '0',
            up = row != 0 ? battlefield[row-1][col] : '0',
            down = row != size-1 ? battlefield[row+1][col] : '0';

            if (el == left) orcs += 1;
            if (el == up) orcs += 1;
            if (el == right) orcs += 1;
            if (el == down) orcs += 1;
          };
          orcs += 1;
        };
      };  
  }
  
  // Human Side;
  // for aninhado percorre a matriz de 5-9;
  // se tiver mago soma os lados na horizontal e vertical
  // se nao tiver mago soma apenas o elemento diferente de '*';
    for (int row = 0; row < size; row++) {
      for (int col = 5; col < size; col++) {
        el = battlefield[row][col];
        if (el != '*') {
          if (gotHumanWizard) {
            // ternário para não acessar lixo;
            left = col != 5 ? battlefield[row][col-1] : '0',
            right = col != size-1 ? battlefield[row][col+1] : '0',
            up = row != 0 ? battlefield[row-1][col] : '0',
            down = row != size-1 ? battlefield[row+1][col] : '0';

            if (el == left) humans += 1;
            if (el == up) humans += 1;
            if (el == right) humans += 1;
            if (el == down) humans += 1;
          };
          humans += 1;
        };
      };
    };
  
  // tratamento de output
  string warCry; 
  if (orcs == humans) warCry = "Batalha lendaria!";
  else if (orcs > humans) warCry = "Loktar Ogar!!!";
  else warCry = "Pela Alianca!";

  // output
  cout << warCry; 

  // liberação de memória; 
  for (int i = 0; i < size; i++) delete [] battlefield[i];
  delete [] battlefield;
  return 0;
};
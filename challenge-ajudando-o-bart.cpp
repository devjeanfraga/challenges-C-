#include <iostream>
#include <string>
using namespace std;


int main() {
  // Escreva seu código aqui
  int N;
  string text;

  // cin ignora os caracteres de espaço em branco
  // e os deixa no fluxo como lixo; 
  cin >> N; 

  // getline nào ignora os espacos em branco deixados no fluxo; 
  // para corrigir isso usa-se o manipulador std:ws
  // que extrai todos os caracteres de espaç o em branco após cin;
  getline(cin >> ws, text);

  for (int i = N-1; i >= 0; i--) cout << i+1 << ". " << text << endl;
  return 0;
}
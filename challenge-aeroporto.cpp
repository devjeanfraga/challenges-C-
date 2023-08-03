#include <iostream>
using namespace std;

int main() {
  int airports, flights, test = 0;

  while (
    cin >> airports >> flights && 
    (airports > 0 && flights > 0)
  ) {
    int size = airports + 1, greater = 0; 
    int ListOfAirports[size] = {}; // lista de identificadores dos aeroportos indicados no indice do vetor;
    int X, Y;
    string result = "";

    // le os valores de X Y;
    // Acumula o numero de aparições de cada aeroporto;
    for (int i = 0; i < flights; i++) {
      cin >> X >> Y;
      ListOfAirports[X] += 1;
      ListOfAirports[Y] += 1; 
    }
    // retorna o maior numero de aparições;
    for (int j = 0; j < size; j++) if (ListOfAirports[j] > greater) greater = ListOfAirports[j];
    
    // retorna uma lista com os aeroportos que tem o valor igual aos de maior aparições;
    for (int j = 0; j < size; j++) if (ListOfAirports[j] == greater) result += to_string(j) + " ";

    cout << "Teste " << ++test << endl;
    cout << result;
    cout << endl << endl;
  }
  return 0;
}

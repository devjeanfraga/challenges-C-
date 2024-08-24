#include <iostream>
#include <string>
#include<vector>
using namespace std;

void boyerMoore (const std::string &texto, const std::string &padrao);

int main () {
  setlocale(LC_ALL, "pt_BR.UTF-8");

  string texto = "No acidente estiveram envolvidos " 
    "três veículos. O carro do senhor "
    "Antonio ficou destruído. O carro do "
    "senhor José não sofreu grandes "
    "danos no acidente. O carro do senhor "
    "Carlos... bom, depois do acidente, "
    "nem se pode chamar aquilo um carro";

  string padrao = "carro";
  boyerMoore(texto, padrao);
  cout << texto;
};

void boyerMoore (const std::string &texto, const std::string &padrao) {
  vector<int> badChar(256, -1);
  for (int i = 0; i < padrao.size(); i++) {
    int id = (int)padrao[i];
    badChar[id] = i;
  }

  int padraoSize = padrao.size();
  int textoSize = texto.size();
  int deslocamento = 0;

  while (deslocamento <= (textoSize -padraoSize)) {
    int j = padraoSize-1;

    // Enquanto os caracteres corresponderem, continue comparando para trás;
    while (j >= 0 & padrao[j] == texto[deslocamento + j]) {
      j--;
    }

    int asciiID;
    if (j < 0) {

      bool continuarBusca = deslocamento + padraoSize < textoSize;
      asciiID = texto[deslocamento + padraoSize];
      
      int k = 1;
      while(k < deslocamento) {
        cout << texto[deslocamento - k];
        k += 1;
      }
      deslocamento += continuarBusca ? padraoSize - badChar[asciiID] : 1;
    } else {
      asciiID = texto[deslocamento + j]; 
      deslocamento += max(1, j - badChar[asciiID]);
    }
  }
}

/*
  padrao = jean

  
  a jednajnah  janehabjeanemajsd

  1IT = e em jean = j+2 vou parar em n  

*/
#include <iostream>
using namespace std;


int main() {
  // Escreva seu c�digo aqui
  int N, len = 16, test = 0;
  while (cin >> N && N) {
    // Retorno
    string res;

    // Declarações dos elementos(digitos);
    char nextLeftDigit, 
         nextRightDigit; 
    char currLeftDigit, 
         currRightDigit;
    
    // Declarações dos índices;
    int currLeftId, 
        currRightId;
    int nextLeftId,   
        nextRightId;

    // Inicialização e preenchimento da tabela;  
    char alphaNumber[N][len] = {};
    for (int i = 0; i < N; i++) for(int j = 0; j < len; j++) cin >> alphaNumber[i][j];
    
    // 1º for iterar as colunas a partir da 10 posição até a última para obter as letras de cada linha;
    // 0 1
    // A E
    // B C
    // C D
    for (int c = 10; c < len; c++) {
      // 2º for: iterar as linhas verificando os digitos correspondentes às letras;
      //      A   B
      //     /\  /\ 
      //     0 1 2 3 
      //     1 3 5 4
      //     9 6 2 1
      for (int l = 0; l < N-1; l++) { 
        // capturar índices pela fórmula i = 'A' = (ascii 65%5)* 2;
        currLeftId = (alphaNumber[l][c]%5)*2;
        currRightId = currLeftId + 1;
        nextLeftId = (alphaNumber[l+1][c]%5)*2;
        nextRightId = nextLeftId + 1;
 
        // capturar elementos da linha atual e da próxima linha;
        currLeftDigit = alphaNumber[l][currLeftId]; 
        currRightDigit = alphaNumber[l][currRightId]; 
        nextLeftDigit = alphaNumber[l+1][nextLeftId];
        nextRightDigit = alphaNumber[l+1][nextRightId];
  
        currLeftDigit = currLeftDigit == nextLeftDigit || currLeftDigit == nextRightDigit ? currLeftDigit : 0;
        currRightDigit = currRightDigit == nextLeftDigit || currRightDigit == nextRightDigit ? currRightDigit : 0;   
      };
      if (currLeftDigit) res += currLeftDigit;
      else res += currRightDigit; 
      res += " ";
    };
    cout << "Teste " << ++test << endl;
    cout << res << endl;
    cout << endl;
  };
 
  return 0;
};

/*
  B C D D E E
  E B C D C D
  A C D D E C
  256789  
*/
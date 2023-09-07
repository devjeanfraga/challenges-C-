#include <iostream>
using namespace std;

int main() {
  // Escreva seu c�digo aqui
  // Declarações dos elementos(digitos);
  char leftDigit, 
       rightDigit,
       nextLeftDigit,
       nextRightDigit; 

  // Declarações dos índices;     
  int leftId, 
      rightId, 
      nextLeftId,   
      nextRightId;

  int N, len = 16, test = 0;
  while (cin >> N && N) {
    string res;
    // Inicialização e preenchimento da tabela;
    char alphaNumber[N][len] = {};
    for (int i = 0; i < N; i++) for(int j = 0; j < len; j++) cin >> alphaNumber[i][j];

    // 1º for - capturar o pivô: iterar as colunas a partir da 10 posição para obter a 1º letra de cada coluna e seus respectivos valores;
    for (int c = 10; c < len; c++) {
      bool isLeft, isRight;
      leftId = (alphaNumber[0][c]%5)*2, rightId = leftId + 1;
      leftDigit = alphaNumber[0][leftId], rightDigit = alphaNumber[0][rightId];

      // 2º for: iterar as linhas verificando os digitos correspondentes às letras;
      for (int l = 0; l < N-1; l++) {
        nextLeftId = (alphaNumber[l+1][c]%5)*2, nextRightId = nextLeftId + 1;
        nextLeftDigit = alphaNumber[l+1][nextLeftId], nextRightDigit = alphaNumber[l+1][nextRightId];

        isLeft = leftDigit == nextLeftDigit || leftDigit == nextRightDigit;
        isRight = rightDigit == nextLeftDigit || rightDigit == nextRightDigit;
        if (!isLeft || !isRight) break;  
      };
      if (isLeft) res += leftDigit;
      else res += rightDigit; 
      res += " ";
    };
    cout << "Teste " << ++test << endl;
    cout << res << endl;
    cout << endl;
  };
 
  return 0;
};
/*
A  1-7    A  9-0 
B  3-9    B  7-5   
C  0-8    C  8-4 
D  5-6    D  6-2 
E  2-4    E  3-1

BCEAEB 
ECCBDA 
384729

A  0-1    A  1-3    A  3-2    
B  2-3    B  5-4    B  0-4    
C  4-5    C  6-8    C  5-9    
D  6-7    D  7-9    D  7-6   
E  8-9    E  0-2    E  8-1    

B C D D E E
E B C D C D
A C D D E C
256789

23 45
02 54
32 59


A - 0-1
B - 2-3
C - 4-5
D - 6-7
E - 8-9

letter1 - 10
letter2 - 11
letter3 - 12
letter4 - 13
letter5 - 14

0 1 2 3 4 5 6 7 8 9 B C D D E E
1 3 5 4 6 8 7 9 0 2 E B C D C D
3 2 0 4 5 9 7 6 8 1 A C D D E C


currleft = Bi0, currright = Bi1
currleft = currleft == nextleft[0] || currleft == nextright[1] ? currleft : -1;
currright = currright == nextleft[0] || currright == nextleft[0] ? currright : -1;

*/
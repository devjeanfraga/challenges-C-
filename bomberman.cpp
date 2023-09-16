#include <iostream>
using namespace std;
template <class T> 
int binarySearch( T arr[], int len, T value) {
  int start = 0, end = len-1, middle = start + (end-start) / 2;
  
  while (arr[middle] != value && start <= end) {
    if(value < arr[middle]) end = middle-1;
    else start = middle+1;
    middle = start + (end-start) / 2;
  };
  return arr[middle] == value ? middle : -1;
}
int main() {
    int altura, largura;
    cin >> altura >> largura;

    // Leitura do cenário inicial
    string cenario[altura] = {};
    for (int i = 0; i < altura; i++) cin >> cenario[i];

    int monstros[] = {98, 99, 100, 101}; //"b c d e" ascii;
    int direcaoX[] = {1, -1, 0, 0};
    int direcaoY[] = {0, 0, 1, -1};

    int segundos;
    cin >> segundos;

    while (segundos--) {
        bool jaAndeiComEsseMonstro[altura][largura] = {};
        for (int linha = 0; linha < altura; linha++) {
            for (int coluna = 0; coluna < largura; coluna++) {
                int x, y;
                char reverse;
                if (
                    cenario[linha][coluna] != 'x' && 
                    cenario[linha][coluna] != 'o' &&
                    jaAndeiComEsseMonstro[linha][coluna] != true
                ) {
                  int indice = binarySearch<int>(monstros, 3, int(cenario[linha][coluna]));
                  cout << "monstro: " << cenario[linha][coluna]<< " indice: " << indice << endl;
                  x = direcaoX[indice];
                  y = direcaoY[indice];
                  x += linha; 
                  y += coluna;
                  /*
                    ***explicação da expressão indice ^ 1***
                    ^ operador XOR(OU EXCLUSIVO) bit a bit 
                    Ex: indice = 0 que aponta para 'b';
                    Análise é feita de cima pra baixo da esquerda para direita;
                               ⇩ ⇩  
                    0 em bin = 0 0 
                                ^   XOR ou exclusivo, verdadeiro se apenas tiver um verdadeiro
                    1 em bin = 0 1
                               ⇩ ⇩
                               f v
                               0 1 
                    retorna 01 = 1 em dicimal 
                    logo o indice = 1 que aponta para 'c';
                  */
                  indice = indice ^ 1;
                  reverse = monstros[indice];
                  bool estaDentroDosLimites = (x >= 0 && x < altura) && (y >= 0 && y < largura); 
                  if (!estaDentroDosLimites || cenario[x][y] != 'o') cenario[linha][coluna] = reverse;
                  else {
                    cenario[x][y] = cenario[linha][coluna];
                    cenario[linha][coluna] = 'o';
                    jaAndeiComEsseMonstro[x][y] = true;
                  };
                };
            };
        };

    };

    // Imprima a cena final
    for (int i = 0; i < altura; i++) {
        cout << cenario[i] << endl;
    };
    return 0;
};

#include <iostream>
using namespace std;

int main() {
  int qtyRow, qtyCol, qtyInstructions;
  while (
    cin >> qtyRow >> qtyCol >> qtyInstructions && 
    (qtyRow && qtyCol && qtyInstructions)
  ) {
    int id, row, col, stickers = 0;
    char arena[qtyRow][qtyCol] = {};
    string instructions;
    for (int i = 0; i < qtyRow; i++) for (int j = 0; j < qtyCol; j++) {
      cin >> arena[i][j];
      switch (arena[i][j]) {
        case 'N': id = 0; break;
        case 'L': id = 1; break;
        case 'S': id = 2; break;
        case 'O': id = 3; break;
        default: continue; break;
      
      };
      row = i, col = j;
    }; 

    char cardinals[] = {'N', 'L', 'S', 'O'};
    int xPosition[] = {-1, 0, 1, 0};
    int yPosition[] = {0, 1, 0, -1};

    cin >> instructions;
    for (int i = 0; i < qtyInstructions; i++) {
      int x, y; 
      if ( instructions[i] != 'F') {
        id +=  instructions[i] == 'D' ? 1 : -1;
        id = (id+4)%4;
        continue;
      };
      x = row + xPosition[id];
      y = col + yPosition[id];

      bool boundsCheck = x >= 0 && x < qtyRow && y >= 0 && y < qtyCol;
      if (boundsCheck && arena[x][y] != '#')  {
        if (arena[x][y] == '*') stickers += 1;
        arena[x][y] = arena[row][col];
        arena[row][col] = '.';
        row = x, col = y; 
      };
    };
    cout << stickers << endl;    
  };
  
  return 0;
};

/*
rali
* Objetivo: determinar o qty de figurinhas coletadas; 
* NxM matriz
* celulas ocupas por figurinhas
* celulas vazias 
* celulas que sustentam o teto da arena
* robos podem estar em qualquer celula exceto as das pilastras
que bloqueioam o movinmento do robo
* D 90 graus direita
* E 90 graus esquerda
* F ande para frente
* robo coleta a figurinha;
* IMPORTANTE, as figurinhas nao sao repostas, logo se ele coleta o a celula fica vaiza
* Se o robo tende a ir para uma celula onde tem pilasta ele permanece no local com a mesma orientaçao
* O mesmo ocorro quando o robo sai da arena

INPUT 
1 linha 3 inteiros
qty linhas
qty colunas
qty d e instrucoes 

linhas maid alta = norte 
linhas mais a esquerda = oeste

'.' = celula vazia
'*' = figurinha da copa
'#' = pilastra

'N', 'S', 'L', 'O' - celula onde o robo inicia o percurso
S chars 'D' = direita - 'E' = esquerda - 'F'= frente;

ultima linha de entrada 
-> 0 0 0 


output
  qtyfigurinhas; 

....*.....
.......*..
.....*....
..*.#.....
...#......
...*N.....
..........
..........
..........
..........

F D F-6 E-2 F-6 E F D F
    N   L   S   O
    0   1   2   3
x  -1   0   1   0
y   0   1   0  -1

N =  L = S = O =   
D= 68 E = 69

0 += (0-1) abs(-1%4)
  d e
  4 4
d = e - d;
e =  d - e
*/

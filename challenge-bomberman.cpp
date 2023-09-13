#include <iostream>
#include <queue>
using namespace std;

struct Monster {
  int x;
  int y; 
};

int main() {
  // Escreva seu código aqui
  // pegar as dimenssões da matriz;
  int r, c;
  cin >> r >> c;
  
  // inicializar struct que recebe as posições dos monstros;
  // inicializar a fila de monstros e a matriz;
  Monster current;
  queue<Monster> queue;
  string grid[r] = {};
  
  // preencher matriz e enfileirar monstros;
  for (int x = 0; x < r; x++) 
    cin >> grid[x];
    for (int y = 0; y < c; y++) {
    if (grid[x][y] != 'o' && grid[x][y] != 'x') {
      current.x = x;
      current.y = y;
      queue.push(current);
    };
  };

  // receber segundos;
  int seconds;
  cin >> seconds; 
  
  // andar com o monstro de acordo com a direção;
  while (!queue.empty()) {
    int row = queue.front().x;
    int col = queue.front().y;

    for (int i = 0; i < seconds; i++) {
      int x, y;
      char reverse; 
      // configurar a direção do monstro;
      switch (grid[row][col]) {
        case 'b':
          x = row+1, y = col;
          reverse = 'c';
          break;
        case 'c':
          x = row-1, y = col;
          reverse = 'b';
          break;
        case 'd':
          x = row, y = col+1;
          reverse = 'e';
          break;
        case 'e':
          x = row, y = col-1;
          reverse = 'd';
          break;
      };

      // Fazer swap para avançar com o monstro na direção definida
      if (grid[x][y] == 'o' && (x >= 0 && x < r) && (y >= 0 && y < c)) {
        char temp = grid[x][y];
        grid[x][y] = grid[row][col];
        grid[row][col] = temp;
        row = x, col = y;
      } else {
        grid[row][col] = reverse; // reverter a direção do monstro;
        
      };
    };
    // tirar o monstro da fila; 
    queue.pop();
  };

  // output da previsão de jogo; 
  for (int x = 0; x < r; x++) {
    for (int y = 0; y < c; y++) {
      cout << grid[x][y];
    };
    cout << endl;
  };
  return 0;
};

/*
  input  w-h 
  o - white space
  x - wall
  c - monster up
  b - monster down
  e - monster left side
  d - mosnter right side

  seconds = a cada segundo se movem nas suas devidas direçoes
  posição = outof bounds || parede ||  ocupada 
    ? vira a posição oposta e fica parado até o proximo segundo
  movimento feito em ordem crescente da esquerda para a direita e do topo para baixo


      if (grid[row][col] == 'b') {
        x = row+i+1, y = col;
        a = row-i+1 ,b = col; 
      };
      if (grid[row][col] == 'c') {
        x = row-i+1, y = col;
        a = row+i+1, b = col;
      };
      if (grid[row][col] == 'd') {
        x = row, y = col+i+1;
        a = row, b = col-i-1;
      };
      if (grid[row][col] == 'e') {
        x = row, y = col-i+1;
        a = row, b = col+i+1;
      };
*/
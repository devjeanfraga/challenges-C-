#include <iostream>
#include <cmath>
using namespace std;


int main() {
  // Escreva seu código aqui
  int* input = new int [1000];
  int counter = 0;
  while ( cin >> input[counter] ) counter += 1;

  // get dimensions of 2D array;
  counter = sqrt(counter);
  
  // build initial 2D Array; 
  int** grid;
  grid = new int* [counter]; // alloc memory to array;
  for (int i = 0; i < counter; i++) grid[i] = new int [counter];
  
  int x = 0, y = 0;
  for (int i = 0; i < (counter*counter); i++) {
    grid[x][y] = input[i];
    y += 1;
    if (y == counter) {
      x += 1;
      y = 0; 
    };
  }; 

  delete [] input; // free pointer;

  int size = counter; 
  while (size > 1) {
    int rowSum = 0;
    int colSum = 0;

    // sum diagonal 1;
    for (int i = 0; i < counter; i++) rowSum += grid[i][i];
    // sum diagonal 2;
    for (int i = 0; i < counter; i++) colSum += grid[i][counter-i-1];

    // get the row and line to be deleted;
    int rowId = rowSum%counter;
    int colId = colSum%counter;

    // build the new 2D array;
    int** currGrid;
    size -= 1;
    currGrid = new int* [size]; // alloc memory;
    for (int i = 0; i < size; i++) currGrid[i] = new int[size]; 

    // copy de items that are not in the row and the col to be deleted;
    int row = 0, col = 0;
    for (int i = 0; i < counter; i++) {
      if (i == rowId) continue;
      for (int j = 0; j < counter; j++) {
        if (j != colId ) {
          currGrid[row][col] = grid[i][j];
          col += 1; 
        };
        if (col == size) {
          col = 0;
          row += 1;
        }; 
      };
    };

    // delete old grid pointer;
    for (int i = 0; i < counter; i++) delete [] grid[i];
    delete [] grid;
    
    // assign grid to currGrid and update currGrid and counter values;
    grid = currGrid;
    currGrid = NULL;
    counter = size;
 
  };

  // return the value;
  cout << grid[0][0]; 

  // delete pointer; 
  for (int i = 0; i < counter; i++) delete [] grid[i];
  delete [] grid;
  return 0;
};
/*
  definição da linha a ser eliminada:
  somar o valores da diagonais 
  dividir pelo numeor de linhas e pegar o módulo

  difinição da coluna a ser eliminada:
  somar os valores da segunda diagonal
  dividir pelo numero de colunas e pegar o modulo;


  -1 -1 -1
  -1 5 6
  -1 8 9
   
  5 6
  8 9 


*/
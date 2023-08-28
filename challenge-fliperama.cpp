#include <iostream>
using namespace std;

void merge (int arr[], int first, int last, int middle);
void mergesort (int arr[], int left, int right);
int main() {
  // Escreva seu código aqui
  int rounds, tops;
  cin >> rounds >> tops;

  int scores[rounds] = {};
  for (int k = 0; k < rounds; k++) cin >> scores[k];

  mergesort(scores, 0, rounds-1);

  for(int j = 0; j < tops; j++) cout << scores[j] << endl;

  return 0;
}

void merge (
  int arr[], 
  int first, 
  int last, 
  int middle
) {
  // Defini os tamanhos dos arrays temporarios
  int sizeA = middle - first + 1;
  int sizeB = last - middle;

  // Inicializa os arrays temporarios
  int arrA[sizeA] = {};
  int arrB[sizeB] = {};

  // Copia os elementos da primeira metade pro arrayA 
  for (int i = 0; i < sizeA; i++ ) arrA[i] = arr[first+i];
  // Copia os elementos da segunda metade pro arrayB
  for (int j = 0; j < sizeB; j++ ) arrB[j] = arr[middle + 1 + j];

  // Ordena os elementos 
  int leftIdx = 0, rightIdx = 0, idx = first;
  while ( leftIdx < sizeA && rightIdx < sizeB ) {    
    if( arrA[leftIdx] <= arrB[rightIdx] ) {
      arr[idx] = arrB[rightIdx];
      rightIdx += 1;
    } else {
      arr[idx] = arrA[leftIdx];
      leftIdx += 1;
    };
    idx += 1;
  };

  // Copia os elementos restantes
  while ( leftIdx < sizeA ) {
    arr[idx] = arrA[leftIdx];
    leftIdx += 1;
    idx += 1;
  };

  while ( rightIdx < sizeB ) {
    arr[idx] = arrB[rightIdx];
    rightIdx += 1;
    idx += 1;
  };

}

void mergesort (  
  int arr[],
  int left, 
  int right
) {
  //condição de parada
  if ( left >= right ) return;
  int middle = (left + right) / 2;

  // fundi e organiza os elementos da esquerda
  mergesort( arr, left, middle);
  // fundi e organiza os elementos da direita
  mergesort(arr, middle+1, right);
  merge(arr, left, right, middle );
}


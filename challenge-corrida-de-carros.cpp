#include <iostream>
using namespace std;

struct Car {
  int val;
  int id;
};
template<class T> void merge (T arr[], int start, int end, int middle);
template <class T> void mergeSort (T arr[], int start, int end); 

int main() {
  int qtyCars, qtyRounds;
  cin >> qtyCars >> qtyRounds;

  Car curr, 
      arrCars[qtyCars] = {};
  int inputs[qtyCars][qtyRounds] = {};

  for (int x = 0; x < qtyCars; x++) {
    curr.id = x+1, curr.val = 0;

    for (int y = 0; y < qtyRounds; y++) {
     cin >> inputs[x][y];
     curr.val += inputs[x][y];

    };
    arrCars[x] = curr;

  };

  mergeSort<Car>(arrCars, 0, qtyCars-1);
  for (int i = qtyCars-1; i >= qtyCars-3; i--) cout << arrCars[i].id  << endl;

  return 0;
};
// ordem decrescente
template <class T> void merge (T arr[], int start, int end, int middle) {
  int sizeA = middle - start + 1;
  int sizeB = end - middle;
  T* arrA = new T[sizeA];
  T* arrB = new T[sizeB];

  for (int i = 0; i < sizeA; i++) arrA[i] = arr[start+i];
  for (int j = 0; j < sizeB; j++) arrB[j] = arr[j + middle + 1];

  int id = start, idA = 0, idB = 0; 
  while (idA < sizeA && idB < sizeB) {
  if (arrA[idA].val < arrB[idB].val) { 
      arr[id] = arrB[idB];
      idB += 1;

    } else {
      arr[id] = arrA[idA];
      idA += 1;

    };
    id += 1;
  };

  while (idA < sizeA ){
    arr[id] = arrA[idA];
    idA += 1;
    id += 1;
  };

  while (idB < sizeB ){
    arr[id] = arrB[idB];
    idB += 1;
    id += 1;
  }

  delete [] arrA;
  delete [] arrB;
};

template <class T> void mergeSort (T arr[], int start, int end) {
  if (start >= end) return; 
  int middle = (start+end)/2;
  mergeSort<T>(arr, start, middle);
  mergeSort<T>(arr, middle+1, end);
  merge<T>(arr, start, end, middle);
};
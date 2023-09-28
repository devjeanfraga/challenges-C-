#include <iostream>
using namespace std;

void merge (int arr[], int start, int end, int middle);
void mergeSort (int arr[], int start, int end); 

int main() {
  int qty, test = 0;
  while (cin >> qty && qty) { 
    int arrX[qty] = {}, arrY[qty] = {};
    for (int i = 0; i < qty; i++) cin >> arrX[i] >> arrY[i];
    mergeSort(arrX, 0, qty-1);
    mergeSort(arrY, 0, qty-1);
    test += 1;
    cout << "Teste " << test << endl;
    cout << arrX[qty/2] << ' ' << arrY[qty/2] << endl << endl;
  };
  return 0;
};

void merge (int arr[], int start, int end, int middle) {
  int sizeA = middle - start + 1;
  int sizeB = end - middle;
  int* arrA = new int[sizeA];
  int* arrB = new int[sizeB];

  for (int i = 0; i < sizeA; i++) arrA[i] = arr[start+i];
  for (int j = 0; j < sizeB; j++) arrB[j] = arr[j + middle + 1];

  int id = start, idA = 0, idB = 0; 
  while (idA < sizeA && idB < sizeB) {
    if (arrA[idA] >= arrB[idB]) {
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

void mergeSort (int arr[], int start, int end) {
  if (start >= end) return; 
  int middle = (start+end)/2;
  mergeSort(arr, start, middle);
  mergeSort(arr, middle+1, end);
  merge(arr, start, end, middle);
}
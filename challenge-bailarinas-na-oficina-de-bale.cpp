#include <iostream>
using namespace std;
template<class T> void merge (T arr[], int start, int end, int middle);
template <class T> void mergeSort (T arr[], int start, int end); 
struct DataDancer {
  int level;
  int order;
};
int main() {
  int qty;
  cin >> qty;
  int entryOrder[qty] = {};
  DataDancer levelOrder[qty] = {};
  DataDancer dancer;
  for (int i = 0; i < qty; i++) {
    cin >> entryOrder[i];
    dancer.level = entryOrder[i];
    dancer.order = i;
    levelOrder[i] = dancer;
  };
  mergeSort<DataDancer>(levelOrder, 0, qty-1);

  int size = sizeof(entryOrder)/sizeof(entryOrder[0]);
  qty = 0;
  for (int j = 0; j < size; j++) {
    DataDancer d = levelOrder[j];
    for ( int i = d.order; i < size; i++ ) {
      int currLevel = entryOrder[i];
      if ( currLevel >= d.level) continue;
      qty += 1;
    };
  }; 
  cout << qty; 
  return 0;
};

template <class T> void merge (T arr[], int start, int end, int middle) {
  int sizeA = middle - start + 1;
  int sizeB = end - middle;
  T* arrA = new T[sizeA];
  T* arrB = new T[sizeB];

  for (int i = 0; i < sizeA; i++) arrA[i] = arr[start+i];
  for (int j = 0; j < sizeB; j++) arrB[j] = arr[j + middle + 1];

  int id = start, idA = 0, idB = 0; 
  while (idA < sizeA && idB < sizeB) {
    if (arrA[idA].level <= arrB[idB].level) {
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
}
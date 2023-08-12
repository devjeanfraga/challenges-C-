#include <iostream>
#include <string>
using namespace std;

bool compare (string sA, string sB) {
  int size = sA.length();
  int i = 0, result;
  while ( size-- ) {
    if (sA[i] != sB[i]) break;
    i += 1;
  };
  return sA[i] < sB[i];
};
void merge (string arr[], int start, int end, int middle) {
  // definir size dos arrays
  // [0,1] 1/2 = 0, middle = 0, start = 0 (middle - start + 1);
  int sizeA =  middle - start + 1;
  int sizeB = end - middle;

  string arrA[sizeA] = {};
  string arrB[sizeB] = {};
  
  for (int i = 0; i < sizeA; i++) arrA[i] = arr[start + i];
  for (int k = 0; k < sizeB; k++) arrB[k] = arr[middle + k + 1];

  int id = start, leftId = 0, rightId = 0;
  while ( leftId < sizeA && rightId < sizeB ) {
    bool isSorted = compare(arrA[leftId], arrB[rightId]);
    
    if ( isSorted ) {
      arr[id] = arrA[leftId];
      leftId += 1;

    } else {
      arr[id] =  arrB[rightId];
      rightId += 1;

    };
    id += 1;
  };

  while ( leftId < sizeA ) {
    arr[id] =  arrA[leftId];
    leftId += 1;
  	id += 1;
  };

  while ( rightId < sizeB ) {
    arr[id] = arrB[rightId];
    rightId += 1;
    id += 1;
  };
}
void mergeAlphaSort( string data[], int start, int end ) {
  if (start >= end ) return; 
  int middle = (start + end) / 2;
  mergeAlphaSort(data, start, middle);
  mergeAlphaSort(data, middle + 1, end);
  merge(data, start, end, middle);
}
int main() {
  // Escreva seu código aqui
  int n, winner;
  cin >> n >> winner;

  string students[n];
  for (int i = 0; i < n; i++) cin >> students[i];

  mergeAlphaSort(students, 0, n-1);
  cout << students[winner-1] << endl;
  return 0;
}
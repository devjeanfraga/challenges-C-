#include <iostream>
#include <string>
using namespace std;
const int size = 12;

// is string A bigger than string B;
int compare (string A, string B) {
  int i = 0; 
  while (A[i] == B[i] && i < A.length()) i++;
  i = A[i] - B[i];
  return i; // A < 0 | A < 0 | A == 0
};

struct Student {
  string name;
  int total;
};

template<class T> void merge (T arr[], int start, int end, int middle);
template <class T> void mergeSort (T arr[], int start, int end); 

int main() {
  int qty, test = 1; 
  while (cin >> qty && qty) {

    int score;
    Student student, list[qty] = {}; //declarar lista e variável de estudantes;
    for (int i = 0; i < qty; i++) {
      int smaller = 1001, bigger = -1;
      student.total = 0;
      cin >> student.name;
      for (int j = 0; j < size; j++) {
        cin >> score;
        student.total += score;

        if (score < smaller) smaller = score; //pegar o menor valor
        if (score > bigger) bigger = score; // pegar o maior valor;

      };
      student.total -= (smaller+bigger); // somar o maior e o menor valor e tirar do total;
      list[i] = student; // adicionar estudande à lista;
    };
    
    mergeSort<Student>(list, 0, qty-1); // ordernar a lista por por maior total ou por ordem alphabética;

    cout << "Teste " << test << endl;
     int b = 1; // inicializar a classifição;
    score = list[0].total; // inicializar o score para comparação;
    for (int i = 0; i < qty; i++) {
      bool isDiffScore = list[i].total != score;
      if (isDiffScore) { // se pontuações diferentes indice mais 1, b = classificação anterior, score atualiza pra pontuaçao atual;
        cout << i+1  << ' ' <<  list[i].total << ' ' <<  list[i].name << endl;
        b = i+1;
        score = list[i].total;
      } else { // se iguais classificação = classificação anterior;
        cout << b  << ' ' <<  list[i].total << ' ' <<  list[i].name << endl; 
      };
    };
    cout << endl;
    test++;
  };
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
    if (arrA[idA].total == arrB[idB].total) {
      int isASmallerThanB = compare(arrA[idA].name, arrB[idB].name);
      if (isASmallerThanB < 0) arr[id] = arrA[idA], idA += 1;
      else arr[id] = arrB[idB], idB += 1;
      
    } else if (arrA[idA].total < arrB[idB].total) {
      arr[id] = arrB[idB];
      idB += 1;
    } else  {
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

/*
1
1
3
3
3
6
*/
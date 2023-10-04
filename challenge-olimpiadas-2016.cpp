#include <iostream>
using namespace std;

struct Country {
  int val;
  int id;
};
template<class T> void merge (T arr[], int start, int end, int middle);
template <class T> void mergeSort (T arr[], int start, int end); 

int main() {
  //inicializar e inputar qty de paises e de modalidades;
  int qtyCountries, qtyModalities;
  cin >> qtyCountries >> qtyModalities;

  //inicializar e inputar quadro de medalhas e modalidades;
  int inputs[qtyModalities*3] = {};
  for (int i = 0; i < qtyModalities*3; i++) cin >> inputs[i];

  // Atribuir o input à posição em counter e somar as vezes que ela aparece;
  int counter[qtyCountries+1] = {};
  for (int i = 0; i < qtyModalities*3; i++) counter[inputs[i]] += 1;
  
  // atribuir a qty e o id do pais a um tipo e guardá-los em um vetor;
  Country countryData, result[qtyCountries] = {};
  for (int i = qtyCountries; i > 0; i--) {
    countryData.id = i;
    countryData.val = counter[i];
    result[qtyCountries-i] = countryData;
  };

  // ordenar o vetor de forma decrescente;
  mergeSort<Country>(result, 0, qtyCountries-1);

  // retornar os paises em ordem decresncente de qty, caso tenha empate nas qty retornar o país com o menor id; 
  for (int i = 0; i < qtyCountries; i++) cout << result[i].id  << ' ';

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
    if (arrA[idA].val == arrB[idB].val) { // se for igual classificar pelo menor id
      if (arrA[idA].id < arrB[idB].id ) arr[id] = arrA[idA], idA += 1;
      else arr[id] = arrB[idB], idB += 1;

    } else if (arrA[idA].val < arrB[idB].val) { 
      arr[id] = arrB[idB];
      idB += 1;

    } else  if (arrA[idA].val > arrB[idB].val) {
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

/*
  valor1 > valor2 
  idValor1;

  valor1 == valor2
    idValor1 > idValor2
    idValor2;


*/
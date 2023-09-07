#include <iostream>
#include <cmath>
#define ll long long int
using namespace std;

template <typename T> class Node {
  private: 
    template<typename U> friend class Myqueue;
  public: 
    T data;
    Node<T>* next;
    Node () {
      this->next = NULL;
    };
};

template <class T> class Myqueue {
  public: 
  Node<T>* head;
  Node<T>* tail;
  int size;
  Myqueue() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
  };

  bool isEmpty () {
    return head == NULL && size == 0;
  };

  T dequeue () {
    T result;
    if (this->isEmpty()) return -1;
    result =  head->data;
    if (size == 1) {
      head = NULL;
      tail = head;
    } else head = head->next;
    size -= 1;
    return result;
  };

  void enqueue (T value) {
    Node<T>* newNode = new Node<T>[1];
    newNode->data = value;
    if (!head) {
      head = newNode;
      tail = head;
    } else {
      tail->next = newNode;
      tail = newNode; 
    }
    size += 1;
  };
};

template <typename T> int getDigit (T number, int position) {
  T operation = abs(number)/pow(10, position);
  operation %= 10;
  return operation;
};

template <typename A> int getSize (A number) {
  return log10(number) + 1;
};

template <typename J> int getGreater (J arr[], int size) {
  int max = 0;
  for (int i = 0; i < size; i++) {
    int current = getSize(arr[i]);
    if (current > max) max = current;
  }
  return max;
};

template <typename C, typename R> R radixSort (C arr[], int size) {
  C res[size] = {};
  R maxNDigits = getGreater<C>(arr, size);

  for (int i = 0; i < maxNDigits; i++) {
    Myqueue<C> queue[10];
    
    for (int j = 0; j < size; j++) {
      C curr = arr[j];
      int idx = getDigit<C>(curr, i);
      queue[idx].enqueue(curr);
    };

    int id = 0;
    for (int j = 0; j < 10; j++) {
      while (!queue[j].isEmpty()) {
        arr[id] = queue[j].dequeue();
        id+=1;  
      };   
    };

    // for (int j = 0; j < size; j++) cout << arr[j] << ' ';
    // cout << endl;
  }
  return maxNDigits;
};

template <typename U> void sort (U arr[], int start, int end, int middle) {
  int sizeA = middle - start + 1, sizeB = end - middle;
  auto *arrA = new U[sizeA], *arrB = new U[sizeB];
  
  for(auto i = 0; i < sizeA ; i++) arrA[i] = arr[start + i];
  for(auto i = 0; i < sizeB ; i++) arrB[i] = arr[middle + 1 + i];

  int idA = 0, idB = 0, id = start;
  while (idA < sizeA && idB < sizeB) {
    if (arrA[idA] > arrB[idB]) {
      arr[id] = arrB[idB];
      idB += 1;
    } else {
      arr[id] = arrA[idA];
      idA += 1;
    };
    id += 1;
  };

  while (idA < sizeA) {
    arr[id] = arrA[idA];
    idA += 1;
    id += 1;
  };

  while (idB < sizeB) {
    arr[id] = arrB[idB];
    idB += 1;
    id += 1;
  };

  delete[] arrA;
  delete[] arrB;
};
template <typename T>void mergeSort (T arr[], int start, int end) {
  if (start >= end) return;
  int middle = start + (end-start)/2;
  mergeSort(arr, start, middle);
  mergeSort(arr, middle + 1, end);
  sort<T>(arr, start, end, middle);
}
template <typename U> bool binarySearch (U arr[], int start, int end, U value) {
  int mid = start + (end-start) / 2;
  while (arr[mid]!= value && start <= end) {
    if(arr[mid] > value) end = mid-1;
    else start =  mid + 1;
    mid = start + (end-start) / 2;
  };
  return arr[mid] == value;
};

int main() {
  // Escreva seu c�digo aqui
  int N;
  cin >> N;
  ll arr[N];
  for (int j = 0; j < N; j++) cin >> arr[j];
  int length = sizeof(arr)/sizeof(arr[0]);
  //radixSort<ll, int>(arr, length);
  mergeSort<ll>(arr, 0, length);
  ll value;
  while (cin >> value ) cout << ( binarySearch<ll>(arr, 0, length, value) ? "sim" : "nao") << endl;
  return 0;
};

/*

    for(int k = 0; k < 10; k++) cout << queue[k].dequeue() << ' ';
    cout << endl;
*/
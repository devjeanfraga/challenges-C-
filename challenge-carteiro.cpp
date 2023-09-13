#include <iostream>
using namespace std;

template <class T> 
int binarySearchWithLowerBound( T arr[], int len, T value); 

int main() {
  // Escreva seu código aqui
  int qtyHouses, qtyOrders, totalTime = 0; 
  cin >> qtyHouses >> qtyOrders; 
  
  int street[qtyHouses] = {};
  for (int i = 0; i < qtyHouses; i++) cin >> street[i];

  int orders[qtyOrders] = {};
  for (int i = 0; i < qtyOrders; i++) cin >> orders[i];


  int size =  sizeof(street)/sizeof(street[0]);

  int previousId = 0, timeSpent; 
  for (int i = 0; i < qtyOrders; i++) {
    int currentId = binarySearchWithLowerBound<int>(street, size, orders[i]);
    timeSpent = abs(currentId-previousId);
    previousId = currentId;
    totalTime += timeSpent;  
  };
  cout << totalTime;  

  // int arr[] = {1,5,6,10,20,25,28};
  // int res = binarySearch<int>(arr,4,3);
  // cout << res; 
  return 0;
};

template <class T> 
int binarySearchWithLowerBound( T arr[], int len, T value) {
  int start = 0, end = len-1;
  int res;
  while (start <= end) {
    int middle = start + (end - start ) / 2;
    if (value <= arr[middle]) {
      res = middle;
      end = middle-1;
    } else {
      start = middle+1;
    };
   
  };
  return res;
};

/*
 indices    0 1  2  3  4
 elementos  1 5 10 20 40
 encomendas 10 20 10 40 1

  total = 0;
  2-0 = total += 2;
  3-2 = total += 1;
  3-2 = total += 1;
  4-2 = total += 2;
  0-4 = total += 4;
  total = 10; 

  1 5 6 10 20 40

*/
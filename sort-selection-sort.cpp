#include <iostream>
using namespace std;

template<class T>
void  selectionSort (T arr[], int len);

int main() {
  // Escreva seu código aqui
  int nums[10] = {10,2,1,9,3,8,4,7,6,5}; 
  selectionSort<int>(nums, 10);
  for (int i = 0; i < 10; i++) cout  << nums[i] << ' ';
  return 0;
};


template<class T>
void selectionSort (T arr[], int len) {
  int lowest;
  for (int i = 0; i < len-1; i++) {
    lowest = i;
    for (int j = lowest+1; j < len; j++) {
      if (arr[lowest] > arr[j]) {
        lowest = j; 
      };
    };

    if(i != lowest) {
      T temp = arr[i];
      arr[i] = arr[lowest];
      arr[lowest] = temp; 
    }; 
  };
};
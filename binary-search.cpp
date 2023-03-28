#include <iostream>
using namespace std;

template <class T> 
int binarySearch( T arr[], int len, T value);

int main() {
  // Escreva seu código aqui
  int nums[10] = {1,2,3,4,5,6,7,8,9,10}; 
  int n = binarySearch<int>(nums, 10, 20);
  cout <<  n ;
  
  return 0;
};

template <class T> 
int binarySearch( T arr[], int len, T value) {
  int start = 0, end = len-1, middle = int( (start + end) / 2);
  
  while (arr[middle] != value && start <= end) {
    if(value < arr[middle]) end = middle-1;
    else start = middle+1;
    middle = int( (start + end) / 2);
  };
  return arr[middle] == value ? middle : -1;
  /*
    ***Anoter away***

    int start = 0, end = len-1;
    
    while (start <= end) {
      middle = int((start + end) / 2);
      if (arr[middle] == value ) return middle;
      if(value < arr[middle]) end = middle-1;
      else start = middle+1;
    };
    return -1;
  */
};
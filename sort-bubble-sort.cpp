#include <iostream>
using namespace std;

template<class T> 
void bubbleSort (T arr[], int len) {
  bool isSwap =  false; 
  int lastSwapIdx = -1;
  len = len - 1;
  do {
    isSwap = false;
    lastSwapIdx = -1;
    
    for (int i = 0; i <= len-1; i++) {
      T firstEl = arr[i];
      T secondEl = arr[i+1];

      if (secondEl < firstEl) {
        arr[i] = secondEl;
        arr[i+1] = firstEl;
        isSwap = true;
        lastSwapIdx = i; 
      }; 
    }
    len = lastSwapIdx;
  } while (isSwap);

}; 

int main () {
  int nums[10] = {10,2,1,9,3,8,4,7,6,5};
  bubbleSort<int>(nums, 10);
  char letters[10] = {'j','c','k','h','y','a','b','d','i','r'};
  bubbleSort<char>(letters, 10);

  for (int i = 0; i < 10; i++) cout << nums[i] << ' ';
  cout << endl; 
  for (int i = 0; i < 10; i++) cout << letters[i] << ' ';

  return 0;
};
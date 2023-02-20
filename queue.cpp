#include <iostream>
#include <string>
#include "arrayqueue.h"
using namespace std;

int main() {
  // Escreva seu c�digo aqui
  ArrayQueue<int,5> queue;
  queue.enqueue(10); 
  cout << queue.dequeue() << endl;	  

  return 0;
};

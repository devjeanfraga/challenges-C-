#include <iostream>
#include <string>
using namespace std;

#ifndef ARRAY_QUEUE
#define ARRAY_QUEUE

template <class T, int size = 100>
class ArrayQueue {
public: 
		ArrayQueue () {
			first = last = -1;
		}
		
		void enqueue (T );
		T dequeue ();
		
		bool isFull () {
      // first == 0 || last = size-1 || first = os elementos nao sao retirados do storage, apenas o idice first que anda; 
			return (first == 0 && last == size-1) || first == last + 1;	
		}
		
		bool isEmpty () {
			return first == -1; 		
		}

private: 
    int first, last;
    T storage[size]; 
};

template<class T, int size>
void ArrayQueue<T, size>::enqueue (T el) {
  if(!isFull()) {
    if (last == -1 || last == size-1) {
      storage[0] = el;
      last = 0; 
      if (first == -1) first = 0;  
    } else storage[last+1] = el;
  } else cout << "The queue is full" << endl; 
};

template<class T, int size>
T ArrayQueue<T, size>::dequeue () {
  T temp; 
  temp  = storage[first];
  if (first == last) {
    last = first = -1;
  } else if (first == size-1) {
    first = 0;
  } else first += 1;
  return temp; 
};
#endif


int main() {
  // Escreva seu c�digo aqui
  ArrayQueue<int,5> fila;
  fila.enqueue(10); 	  

  return 0;
};

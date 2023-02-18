#include <iostream>
#include <string>
using namespace std;

#ifndef ArrayQueue;
#define ArrayQueue;

template <class T, int size = 100>
class ArrayQueue {
	public: 
		ArrayQueue () {
			first = last = -1;
		};
		
		void enqueue (T);
		T dequeue ();
		
		bool isFull () {
			return first == 0 && (last == size-1 || first == last + 1);	
		};
		
		bool isEmpty () {
			return first == -1; 		
		};
		
};

#endif

int main() {
  // Escreva seu código aqui	


  return 0;
};

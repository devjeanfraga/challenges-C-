#include <iostream>
#include <string>
using namespace std;


int main() {
  // Escreva seu código aqui	
	int qtyInterval, distancia = 0;

	
	cin >> qtyInterval;

    while (qtyInterval--) {
    	int time, vm; 
      	cin >> time >> vm; 
	  	distancia += time * vm; 
    };  
    cout << distancia << endl;  

  return 0;
};

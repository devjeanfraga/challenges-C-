
#include <iostream>
#include <string>
using namespace std;

struct Student {
	string name;
	int score;
};

int main() {
  // Escreva seu código aqui	
	int qtyStudents, instancia = 0;
  Student previous;
	
	while(cin >> qtyStudents) {
    previous.score = 11; 
    
    while (qtyStudents--) {
      Student current;
      cin >> current.name >> current.score; 
      if (current.score < previous.score) previous = current;
      if ( current.score == previous.score && current.name > previous.name ) previous = current; 
    };  

    cout << "Instancia " << ++instancia << endl;
    cout << previous.name << endl;  
	};
  return 0;
};

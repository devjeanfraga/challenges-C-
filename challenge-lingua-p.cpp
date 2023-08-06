#include <iostream>
#include <string>
using namespace std;

int main() {
  string input, output; 
  getline( cin, input); 

    int sizeInput = input.length(),
        nextIdx = 1;

  /**
  * Decodifica o input;
  */
  bool nextword = true;
  while ( nextword ) {
    /**
    * Retorna a palavra da iteração a ser decodificada;
    */  
    string word; 
    for ( int j = nextIdx; j < sizeInput; j++ ) {
      if (j == sizeInput-1) nextword = false;
      if (input[j] == ' ') {
        nextIdx = j+2;
        break;
      };
      word += input[j];
    };

    /**
    * Concatena as posições sem o "p";
    */  
    for (int j = 0; j < word.length(); j += 2) output += word[j];

    /**
    * Concatena a palavra decodificada a um espaço";
    */  
    output += ' ';
  };

  /**
  * Retorna o input decodificado;
  */
  cout << output; 
  return 0;
} 

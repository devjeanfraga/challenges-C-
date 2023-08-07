#include <iostream>
#include <string>
using namespace std;

int main() {
  string input, output;
  while (cin >> input && input != "0") {
    int i = 0;
    for (int j = 0; j < input.size()-1; j+=2) i += (input[j] - input[j+1]);
    
    if (input.size() % 2 != 0) {
      int last =  input[input.length()-1] - '0';
      i += last;
    };

    cout << (output = (i%11) == 0 ? input + " is a multiple of 11." : input + " is not a multiple of 11.") << endl;
  };
  return 0;
};

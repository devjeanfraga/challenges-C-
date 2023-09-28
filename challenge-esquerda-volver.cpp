#include <iostream>
using namespace std;
;
int main() {
  int qtyInstructions;
  while (cin >> qtyInstructions && qtyInstructions) {
    int index = 0;
    char cardinals[] = {'N', 'L', 'S', 'O'};
    string commands;
    cin >> commands;
    for (int i = 0; i < qtyInstructions; i++) {
      index += commands[i] == 'D' ? 1 : -1;
      index = (index+4)%4;
    };
    cout << cardinals[index] << endl;
  };
  return 0;
};
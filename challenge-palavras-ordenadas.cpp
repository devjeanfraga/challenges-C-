#include <iostream>
#include <string>
using namespace std;

int main() {
  int N;
  string word;
  cin >> N;
  while (N--) {
    int greater = 0;
    bool isSort = true;
    cin >> word;
    
    for (int j = 0; j < word.length(); j++) {
      int current = tolower(word[j]);
      if ( !(current > greater) ) {
        isSort = false;
        break;
      };
      greater =  current;
    }
    cout << word << ": " << (isSort ? 'O' : 'N') << endl;
  }

  return 0;
}
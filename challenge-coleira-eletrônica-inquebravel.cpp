#include <iostream>
#include <cmath>

using namespace std;

int main(){

  char direction;
	int qtyTest, bound, distance;
  bool isNotOutOfBound = false;
  float X= 0, Y= 0; //positions 

  cin >> qtyTest >> bound;
  while (cin >> direction >> distance && qtyTest-- && !isNotOutOfBound) {
    switch (direction) {
      case 'N':
        Y += distance;
        break;
      case 'S':
        Y -= distance;
        break;
      case 'L':
        X += distance;
        break;
      case 'O':
        X -= distance;
        break;
    };
    isNotOutOfBound = sqrt( (X*X) + (Y*Y) ) > bound;
  }
  cout << isNotOutOfBound;
	return 0;
}
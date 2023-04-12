#include <iostream>

using namespace std;

int main(){
  char C;
	long int num, M;
  int D, N= 0, L= 0, O= 0, S= 0;
  cin >> num >> M;
  while (cin >> C >> D && --num ) {
    switch (C) {
      case 'N':
        N += D;
        break;
      case 'L':
        L += D;
        break;
      case 'O':
        O += D;
        break;
      case 'S':
        S += D;
        break;
    };
  }
  bool isOutOfBound = N > M || L > M || O > M|| S > M;
  cout << isOutOfBound;
	return 0;
}


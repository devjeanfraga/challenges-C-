#include <iostream>

using namespace std;

int main() {
  int nStone, nFrogs;
  int initialPosition, distance;
  
  cin >> nStone >> nFrogs;
  int bridge[nStone+1] = {};

  while (nFrogs--) { 
    cin >> initialPosition >> distance; 
    bridge[initialPosition] = 1;
    
    int toRight = initialPosition + distance;
    while (toRight <= nStone) {
      bridge[toRight] = 1;
      toRight += distance;
    }

    int toLeft = initialPosition - distance; 
    while (toLeft >= 0) {
      bridge[toLeft] = 1;
      toLeft -= distance;
    }
  };
  for (int i = 1; i <= nStone; i++) cout << bridge[i] << endl;
  return 0;
}

/*
  i   i   i
  1 2 3 4 5 
  j     j j

  nStone nFrogs  

  initialPosition distance
  initialPosition distance
  initialPosition distance
  initialPosition distance
        
*/
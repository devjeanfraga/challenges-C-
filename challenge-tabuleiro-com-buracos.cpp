#include <iostream>
#include <iomanip>

using namespace std;

int main () {
  int moves, result = 0, moveNumber, x = 4, y = 3; 
  cin >> moves; 
  
  while( cin >> moveNumber && moves--) {
    switch (moveNumber) {
      case 1:
        x += 1;
        y += 2;
        break;

      case 2:
        x += 2;
        y += 1;
        break;

      case 3:
        x += 2;
        y -= 1;
        break;

      case 4:
        x += 1;  
        y -= 2;
        break;

      case 5:
        x -= 1;
        y -= 2;
        break;

      case 6:
        x -= 2;
        y -= 1;
        break;

      case 7:
        x -= 2;
        y += 1;
        break;

      case 8:
        x -= 1;
        y += 2;
        break;          

      default:
        break;
    };
    result += 1;
      /** Black holes **/
    bool isHole = (x == 1 && y == 3) || 
                  (x == 2 && y == 3) || 
                  (x == 2 && y == 5) || 
                  (x == 5 && y == 4);    
    if (isHole) break;
  }; 

  cout << result; 
	return 0; 
}
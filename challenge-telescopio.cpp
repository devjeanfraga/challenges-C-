#include <iostream>
#include <iomanip>

using namespace std;

int main () {
  long int telescopio, star, fotons = 40000000;
  int qtyStars, result = 0;

  cin >> telescopio >> qtyStars;
  
  for(int i = 0; i < qtyStars; i++) {
    cin >> star;
    bool isThereStar = (telescopio * star) >= fotons;
    if (isThereStar) result += 1;
  }
  cout << result; 
	return 0; 
}

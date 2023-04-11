#include <iostream>
#include <iomanip>

using namespace std;
int main () {
  int N, D, C; 
  while (cin >> N >> D >> C ) {
    if ( N != 0 && D != 0 && C != 0 ) cout << N*D*C << endl;
    else break;
  }; 
	return 0; 
}
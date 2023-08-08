#include <iostream>
#include <string>

using namespace std;
int main() {
  int N, test = 0;
  string playerA, playerB;

  while (cin >> N && N !=0 ) {
    int A, B;
    string winner[N] = {};

    cin >> playerA >> playerB;
    for (int i = 0; i < N; i++)  {
      cin >> A >> B; 
      if ( (A+B)%2 == 0 ) winner[i] = playerA;
      else winner[i] = playerB;
    };

    cout << "Teste " << ++test << endl; 
    for (int i = 0; i < N; i++) cout << winner[i] << endl;
  }
  return 0;
};

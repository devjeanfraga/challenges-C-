#include <iostream>

using namespace std;

int main() {
  // Escreva seu c�digo aqui
      int qtyTests, num1, num2;
      string song;
    
      cin >> qtyTests;   
      while (qtyTests--) {
        cin >> num1 >> num2;
        switch (num1+num2) {
        case 0:
          song = "PROXYCITY";
          break;
        case 1:
          song = "P.Y.N.G.";
          break;
        case 2:
          song = "DNSUEY!";
          break;

        case 3:
          song = "SERVERS";
          break;

        case 4:
          song = "HOST!";
          break;

        case 5:
          song = "CRIPTONIZE";
          break;
        case 6:
          song ="OFFLINE DIA";
          break;

        case 7:
          song = "SAL";
          break;

        case 8:
          song = "ANSWER!";
          break;

        case 9:
          song = "RAR?";
          break;
       
        default:
          song = "ANTENNAS WIFI";
          break;
        }
        cout << song << endl;
      };
return 0;
}; 

/*
A
  int input;
  while (cin >> input) {
    if (input != 2002) cout <<  "Senha Invalida" << endl;  
    else {
      cout << "Acesso Permitido" <<  endl;
      break;
    }
  };

B
  int num, acumulador = 0, divisor = 0;
  while (cin >> num && num >= 0) {
    acumulador += num;
    divisor += 1; 
  }
  int res = acumulador/divisor;
  float module = (acumulador%divisor);
  cout << fixed << setprecision(2) << (module/divisor) + res << endl; 
*/
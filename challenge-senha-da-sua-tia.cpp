#include <iostream>
#include<string>
#include<cctype>

using namespace std;
int main() {
  // Escreva seuc�digo aqui
  int size, lower, upper, number;
  int counterLower = 0, counterUpper = 0, counterNumber = 0; 
  string password;
  bool output = false;
  
  cin >> size >> lower >> upper >> number;
  cin >> password;
  if (password.length() >= 6) {
    for (int i = 0; i < password.length(); i++) {
      if (islower(password[i])) counterLower += 1;
      if (isupper(password[i])) counterUpper += 1;
      if (isdigit(password[i])) counterNumber += 1;
    };
    output = (counterLower >= lower) && 
             (counterUpper >= upper) && 
             (counterNumber >= number);
  }
  cout << (output ? "Ok =/" : "Ufa :)"); 
  return 0;
};

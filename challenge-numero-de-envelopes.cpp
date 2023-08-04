#include <iostream>
#include <limits.h>
using namespace std;

int main() {
  long int nLabels, nTypes, label, envelopes = INT_MAX;

  cin >> nLabels >> nTypes;
  int listOfTypes[nTypes+1] = {};
  
  for ( int i = 1; i <= nLabels; i++) { 
    cin >> label;
    listOfTypes[label] += 1;
  }

  for (int i = 1; i <= nTypes; i++) if ( listOfTypes[i] < envelopes ) envelopes = listOfTypes[i];

  cout << envelopes;
  return 0;
}
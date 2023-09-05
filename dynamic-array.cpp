#include <iostream>
#include <cmath>
using namespace std;



int main() {
    //initialization
    int* arr;
    int* arr2;

    arr =  new int[10];
    arr2 =  new int [5];

    cout << "Arr values" << endl;
    for (int i=0; i< 10; i++) arr[i] = i+1;
    for (int i=0; i< 10; i++) cout << arr[i] << ' ';
    
    cout << endl <<  "Arr2 values" << endl;
    for (int i=0; i< 5; i++) arr2[i] = arr[i];
    for (int i=0; i< 5; i++) cout << arr2[i] << ' ';

    delete [] arr; 
    arr = arr2; 
    arr2 = NULL;

    cout << endl << "New Arr values" << endl;
    for (int i=0; i< 5; i++) cout << arr[i] << ' ';

    return 0;
}

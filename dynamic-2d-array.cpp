#include <iostream>
#include <cmath>
using namespace std;



int main() {
    //initialization
    int** arr;
    int** arr2;
    
    // alloc memory
    arr = new int* [5];
    for (int i = 0; i < 5; i++)  arr[i] = new int [5]; 

    // get values
    for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) arr[i][j] = i*10+j+1;

    // print
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) cout << arr[i][j] << ' ';
        cout << endl;
    }; 

     cout << endl << endl;

    // alloc memory to second array
    arr2 = new int* [3];
    for (int i = 0; i < 3; i++)  arr2[i] = new int [3]; 

    //copy odd number to second array; 
    int x = 0, y = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if ( arr[i][j]%2 != 0 )  {
                arr2[x][y] = arr[i][j];
                y += 1;
                if (y == 3) {
                    y = 0;
                    x += 1;
                };
            };
        };
    };

    // print second array
    cout << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cout << arr2[i][j] << ' ';
        cout << endl;
    }; 
    
    // free pointers of the first arr;
    for (int i = 0; i < 5; i++)  delete [] arr[i];

    // free de pointer <5> from first arr 
    delete [] arr;

    cout << endl << endl;
    
    // Assign Arr to Arr2;
    arr = arr2;
    arr2 = NULL;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cout << arr[i][j] << ' ';
        cout << endl;
    }; 
    return 0;
}

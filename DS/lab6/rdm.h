#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int* Rdm(int n) {
    int* randomArray = new int[n];
    srand(time(0));

    for (int i = 0; i < n; i++) {
        randomArray[i] = std::rand() % 100;
    }
    return randomArray;
}

void display(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


#include <iostream>
#include "rdm.h"
using namespace std;

int main(){
    int n = 10;
    int *arr = Rdm(n);
    cout << "Befor sorting!!: ";
    display(arr, n);
    for(int i = 0; i<n-1; i++){
        int min = i;
        for(int j= i+1; j<n; j++){
            min = j;
        }
        int tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
        cout << "After swap " << i << " : ";
        display(arr, n);
    }
    delete[] arr;    
}

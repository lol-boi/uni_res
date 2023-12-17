#include <iostream>
#include "rdm.h"
using namespace std;

int main(){
    int n = 10;
    int *arr = Rdm(n);
    cout << "Before Swap!!" << endl;
    display(arr, n);
    cout << "Sorting: "<< endl;
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
        cout << "After pass " << i << ": ";
        display(arr, n);
    }
    delete[] arr;
}


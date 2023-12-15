#include <iostream>
#include "rdm.h"
using namespace std;


int main(){
    int n = 6;
    int *arr = Rdm(n);
    cout << "Before sort!!"<< endl;
    display(arr, n);
    for(int i = 1; i<n; i++){
        int key = arr[i];
        int j = i -1;
    
        while (j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        cout << "After swap " << i -1<< " : ";
        display(arr, n);
    }
    delete[] arr;
}

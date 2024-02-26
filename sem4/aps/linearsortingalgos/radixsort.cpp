#include <iostream>
using namespace std;

int getmax(int arr[], int s){
    int mx = arr[0];
    for (int i = 1; i < s; i++)
    {
        if (arr[i] > mx)
        {
            mx = arr[i];
        }
    }
    return mx;
}

void countSort(int arr[], int size, int exp){
    int output[10];
    int count[10] = { 0 };  

    for (int i = 0; i < size; i++){ 
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < size; i++){   
        count[i] += count[i - 1];
    }

    output[size]; 

    for (int i = size - 1; i >= 0; i--){   
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < size; i++){
        arr[i] = output[i];   
    }
}

void Radixsort(int arr[], int s){
    int max = getmax(arr, s);
    for (size_t exp = 1; max / exp > 0; exp *= 10){
        countSort(arr, s, exp);
    }
}

int main(){
    int arr[10] = { 80,900,20,508,14,0,192,4,30,48 };
    int sz = 10;
    cout << "Printing array in its orginal condition: ";
    for (int i = 0; i < sz; i++)
    {
        cout << arr[i] << " ";
    }
    Radixsort(arr, sz);
    cout << endl << "Printing array after sorting: ";
    for (size_t i = 0; i < sz; i++)
    {
        cout << arr[i] << "  ";
    }
}

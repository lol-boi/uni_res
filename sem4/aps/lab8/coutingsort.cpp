#include <iostream>
using namespace std;

void CountSort(int arr[], int size)
{
    int output[10];
    int count[10] = { 0 };
    int k = arr[0];         
  for (int i = 1; i < size; i++){
        k = max(k, arr[i]); 
    }
    for (int i = 0; i < size; i++){ 
        count[arr[i]]++;    
    }
    for (int i = 1; i <= k; i++){   
        count[i] += count[i - 1];
    }

    output[size];

    for (int i = size - 1; i >= 0; i--){ 
        output[--count[arr[i]]] = arr[i];
    }
    for (int i = 0; i < size; i++){
        arr[i] = output[i];
    }
}

int main()
{
    int size;
    cout << "Enter the size of the array:";
    cin >> size;
    int arr[size];
    for(int i = 0; i<size; i++){
        arr[i] = rand()%100;
    }
    cout << endl <<  "Printing array in its orginal condition: ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    CountSort(arr, size);
    cout << endl <<  "Printing array after sorting: ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << "  ";
    }
    cout << endl;
}

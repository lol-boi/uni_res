#include <iostream>
#include "rdm.h"
using namespace std;

static int a = 0;
int Partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;
    return i + 1;
}

void QuickSort(int arr[], int n, int left, int right) {
    if (left < right) {
        int pivotIndex = Partition(arr, left, right);
        cout << "After pass ";
        QuickSort(arr,n, left, pivotIndex - 1);
        QuickSort(arr, n,pivotIndex + 1, right);
        cout << "After pass " << a++ << " : ";
        display(arr,n);
    }
}

int main() {
    int n = 11;
    int* array = Rdm(n);

    cout << "Unsorted Array: ";
    display(array, n);
    cout << endl;
    QuickSort(array,n , 0, n - 1);
    cout << endl;
    delete[] array;
    return 0;
}


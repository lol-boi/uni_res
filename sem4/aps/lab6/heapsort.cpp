#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void maxHeapify(int array[], int n, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < n && array[left] > array[largest]){
        largest = left;
    }
    if(right<n && array[right]>array[largest]){
        largest = right;
    } 
    if(largest != i){
        swap(&array[i], &array[largest]);  
        maxHeapify(array,n, largest);
    }
}
void buildMaxHeap(int array[], int n){
    for(int i = n/2-1; i>= 0; i--){
        maxHeapify(array,n,i);
    }
}

void heapsort(int arr[], int n){
    buildMaxHeap(arr,n);
    for(int i = n-1; i>0; i--){
        swap(&arr[0], &arr[i]);
        maxHeapify(arr,i,0); 
    }
}

void display(int array[], int n){
    for(int i = 0; i<n ; i++){
        cout << array[i] << " ";
    }
    cout << endl;
} 

int main(){ 
    int size;
    cout << "Enter the size of the array" << endl;
    cin >> size;
    int randArray[size];
    for(int i=0;i<size;i++)
      randArray[i]=rand()%100;
    cout << "Array before Heapsort: ";
    display(randArray,size); 
    heapsort(randArray,size);
    cout << "After Heapsort: " ;
    display(randArray,size); 
}

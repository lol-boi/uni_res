#include <iostream>
#include <pthread.h>
using namespace std;

int check(int arr[], int n){
    int greatest_index = 0;
    for(int i = 0; i<n; i++){ 
        if((arr[i] > arr[greatest_index]) && (arr[i]> arr[i+1])){
            greatest_index = i;   
        }
    }
    return greatest_index+1;
}

int main(){
    int n;
    cout << "Enter the no of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the array: "; 
    for (int i = 0; i<n; i++){
        cin >> arr[i]; 
    }
    cout << "The index is: " << check(arr,n) << endl; 
}

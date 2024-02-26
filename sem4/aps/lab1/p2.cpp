#include "iostream"
#include <algorithm>
#include <cmath>
#include <cwchar>
#include <functional>
using namespace std;

int* input(){ //recursive imp. of dynamic input through stack concept (stack is formed in recursive function call)
    static int size;    
    static int* arr; 
    int val;
    cin >> val;
    if(val > 0){
        size++;   
        input();
        arr[size--] = val;
    }else{
        arr = new int[size+1];
        arr[0] = size;
    }
    return arr;
}

void find_sqroot(int* arr, int size){

    int tmparr[size]; 
    for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){
            if(arr[i] == arr[j]*arr[j]){
                cout << "Square root is: " << arr[i] << endl;
                return; 
            }
        }
    }
    cout << "NO square root are found in the list." << endl;
    return; 
}

int main (int argc, char *argv[]) {
    cout << "Enter the array: " << endl;
    int* tmplist = input(); //Declared function to take dynamic input from  user 
    cout << endl;
    find_sqroot(tmplist+1,tmplist[0]); // actual function which finds the sqrt in the array
    delete []tmplist; 
    return 0;
}

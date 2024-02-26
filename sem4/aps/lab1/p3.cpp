#include <iostream>
#include <pthread.h>
using namespace std;
int arr_len;
char* input(){
    static int size;
    static char* arr;
    char val;
    cin >> val;
    if(val != '%'){
        size++;
        input();
        arr[size--] = val;
    }else{
        arr = new char[size];
        arr_len = size; 
        --size;
    }
    return arr;

}

void solve(char* arr){
    for(int i = 0; i<arr_len; i++){
        for(int j = 0; j<arr_len; j++){
            if(((int)arr[i])+1 == (int)arr[j]){
                cout << "Letters " << arr[i] << " and " << arr[j] << " apper next to each other alphabetically." << endl;
                return; 
            }
        }
    }
    cout << "No letters appear next to each other alphabetically." << endl;
}
int main (int argc, char *argv[]) { 
    cout << "Enter the elements of the array: "; 
    char* arr = input();
    solve(arr); 
    delete []arr; 
    return 0;
}

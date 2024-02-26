#include <iostream>
#include <utility>
using namespace std;

int* input(){
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
int main (int argc, char *argv[]) {
    int* val = input();

    for(int i = 0; i<val[0]; i++){
        cout << val[i+1];
    } 
    delete []val; 
    return 0;

}


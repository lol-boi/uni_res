#include <iostream>
using namespace std;

int main(){
    int a; 
    int b[10];
    cout << "Enter: ";
    for(int i =0;i<10; i++){
        cin >> a;
        b[i] = a; 
    } 
    for(int i = 0; i<10; i++){
        cout<< b[i];
    }
}

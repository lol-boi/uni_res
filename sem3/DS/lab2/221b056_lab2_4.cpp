#include <iostream>
using namespace std;

int product(int a , int b){
    int pro = 0 ; 
    for(int i = 0; i<b; i++){
        pro += a;
    }
    return pro;
}

int main(){
    int num1, num2;
    cout << "Enter the two numbers: ";
    cin >> num1 >> num2;
    cout << product(num1, num2);
}
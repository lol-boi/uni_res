#include <iostream>
using namespace std;

void fib (int n){
    int num1 = 0;
    int num2 = 1;
    cout << num1 << " " << num2<< " ";
    for(int i =0 ; i< n-2; i++){
       int tmp = num2;
       num2 = num1+num2;
       num1 = tmp;
       cout << num2 << " "; 
    }
}

int main(){
    cout << "Enter a number: ";
    int num;
    cin >> num;
    fib(num);
    return 0;
}
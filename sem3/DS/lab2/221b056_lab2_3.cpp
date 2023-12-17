#include <iostream>
using namespace std;

int gcd(int n1, int n2){
    int tmp;
    int s;
    if(n1 > n2)
        s = n2;
    else
        s = n1;
    int gcd = 0;
    for(int i = 1 ; i<=s; i++){
        if(n1 % i == 0 && n2 % i ==0){
           gcd = i; 
        }
    }
    return gcd;
}

int main(){
    int num1, num2;
    cout << "Enter the two numbers: ";
    cin >> num1 >> num2;
    cout << gcd(num1, num2);
}
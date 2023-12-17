#include <iostream>
using namespace std;

int convert(int a){
    int tmp;
    int num = 0; 
    int pro = 1; 
    while(a!= 0){
        tmp = a%2;
        a /= 2;
        if(tmp == 0) pro *= 10; 
        else{
            num += pro; 
            pro *= 10;
        } 
            
    }
    return num;
}

int main(){
    int num1, num2;
    cout << "Enter the number: ";
    cin >> num1;
    cout << convert(num1);
}
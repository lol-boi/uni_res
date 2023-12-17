#include <iostream>
using namespace std;

int convert(int a){
    int num = 0; 
    int tmp;
    int pro;
    int count = 0;
    while(a != 0 ){
        tmp = a %10;
        a /= 10;
        if(tmp == 0)
            count++;
        else{
            pro = 1;
            for(int i = 0 ;i<count; i++)
                pro *= 2;
        
        num += pro;
        count++;
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
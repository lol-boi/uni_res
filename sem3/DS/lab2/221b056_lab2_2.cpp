#include <iostream>
using namespace std;

int find_sum(int n){
    int sum  = 0;
    for(int i = 1; i<=n; i++){
       sum += (i*i);

    }
    return sum;
}

int main(){
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << find_sum(num);
}
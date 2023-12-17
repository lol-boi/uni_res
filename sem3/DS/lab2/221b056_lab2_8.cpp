#include <iostream>
using namespace std;

int find_fact(int n, int r){
    int t1 = 1, t2 = 1, t3 = 1;
    
    for(int i = 1 ; i < n; i++){
        t1 *= i;
    }
    for(int i = 1; i<r; i++){ t2 *= i;}
    for(int i=1; i<n-r; i++){t3 *= i;}

    return t1/(t3*t2);
}

int main(){
    cout << "Enter n and r: ";
    int n,r;
    cin >> n >> r;
    cout << "The factor is: " << find_fact(n,r) << endl;
}

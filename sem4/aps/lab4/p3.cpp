#include <iostream>
using namespace std;

void solution(float* arr, int size){
    int greatest = arr[0]; 
    int sol, a, b; 
    for(int i = 0; i<size; i++){
        sol = arr[i]; 
        for(int j = i+1; j<size; j++){
            sol += arr[j];
            if(greatest < sol){
                greatest = sol;
                a = i;
                b = j;
            }
        }
    }
    cout << sol << endl << a << " " << b << endl;
}

int main (int argc, char *argv[]) {
    float a[] = {4,-5, 8,-1, 3, -4.2, 0, 2, 12, 13};
    int size = sizeof(a)/sizeof(a[0]);
    solution(a,size);
    return 0;
}

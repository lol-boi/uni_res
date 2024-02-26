#include <iostream>
using namespace std;

void solution(int* arr1, int* arr2, int x, int size){
    int a,b;
    for(int i = 0; i<size; i++){
        for(int j = 0; j< size; j++){
            if(arr1[i] + arr2[j] == x){
                cout << i << " " << j << endl;      
                return;
            }
        } 
    }
    cout << "no" << endl;
}

int main (int argc, char *argv[]) {
    int a1[] = {4,5,8,1,3,9,0,2};
    int a2[] = {2,3,35,32,12,9,2};
    int size = sizeof(a1)/ sizeof(a1[0]);  
    int x = 12;
    solution(a1,a2,x,size);
    return 0;
}

#include <iostream>
using namespace std;

int find(string sen, string word){
    int tmp;
    char ch= ' ';
    for(int i =0; i<sen.length(); i++){
        if((sen[i] == ch || sen[i+word.length()] == ch) || sen[i+word.length()] == '\0'){
            tmp =1;
            for(int j=0;i<word.length(); j++){
                if(sen[i+j+1] == word[j]){
                    tmp = 0; 
                    break;
                } 
            }
            if (tmp == 1){
             return 1;
            }
        }
    }
    return 0;
}

string* find_unknowns(string sen, string arr[],int n){
    static string u_arr[100];
    int counter = 0;  
    for(int i = 0; i<n; i++){
        if(find(sen, arr[i]) == 0){
            u_arr[counter++] = arr[i];
        }
    }
    return u_arr;
}

int main(){
    string srr[100];
    cout << "Enter the known words, enter 'end' to stop entering words: ";
    int a = 0;
    string tmp;
    cin >> tmp;
    do{
        srr[a++] = tmp;
        cin >> tmp;
    } 
    while (tmp != "end");
    cout << "Enter the string: ";
    string sen;
    cin >> sen;
    string* u_words;
    u_words = find_unknowns(sen,srr,a);
    cout << "Unknowns are: ";
    for(int i = 0; i<100; i++){
        cout<< u_words[i] << " ";
    }
    cout << endl;
}

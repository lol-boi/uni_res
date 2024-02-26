#include <iostream>
using namespace std;

void nextletter(char c){
    if(c == 'z' || c == 'Z'){
        switch(c){
            case 'z':
                cout << "The next letter is: a" << endl;
                break; 
            case 'Z':
                cout << "The next letter is: A" << endl;
                break; 
        }
    }else{
        int val = (int)c;
        cout << "The next letter is: " << (char)(val+1) << endl;
    }
}

int main (int argc, char *argv[]) {
    bool flag = true; 
    cout << "Hi! I'm a clever computer program that knows the alphabet."<< endl; 
    do{
        char input;
        cout << "Please enter a letter:";
        cin >> input;
        if ((input > 'a' && input <= 'z') || (input > 'A' && input <= 'Z') ){
            nextletter(input);
            cout << "Do you want to enter another letter (y = yes)?";
            cin >> input;
            if(input != 'y'){
                flag = false;
                cout << "Goodbye" << endl;
            }            
        }else{
            cout << "Enter a char type value!!" << endl; 
        }
    }while(flag == true);    
    return 0;
}

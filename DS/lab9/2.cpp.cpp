#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
    Node* top;

   public:
    Stack() { top = NULL; }

    void push(int data) {
        Node* newnode = new Node;
        newnode->data = data;
        newnode->next = top;
        top = newnode;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        cout << "Popped element: " << top->data << endl;
        top = top->next;
    }

    void display() {
        if (top == NULL) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        Node* ptr = top;
        while (ptr != NULL) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, data;

    while (true) {
        cout << endl << "Menu:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to push: ";
                cin >> data;
                s.push(data);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.display();
                break;

            case 4:
                exit(0);

            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }
    return 0;
}

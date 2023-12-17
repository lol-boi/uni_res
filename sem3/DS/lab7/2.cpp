#include <iostream>

using namespace std;


struct Node {
    int data;
    Node* next;
};

Node* Insert_Beginning(Node* head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    return newNode;
}


Node* Insert_Position(Node* head, int value, int position) {
    Node* newNode = new Node;
    newNode->data = value;

    if (position == 1 || head == nullptr) {
        newNode->next = head;
        return newNode;
    }

    Node* current = head;
    for (int i = 1; i < position - 1 && current->next != nullptr; ++i) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
}


Node* Insert_End(Node* head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        return newNode;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;

    return head;
}


void DisplayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int choice, value, position;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at the beginning\n";
        cout << "2. Insert at specified position\n";
        cout << "3. Insert at the end\n";
        cout << "4. Display linked list\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                head = Insert_Beginning(head, value);
                break;
            case 2:
                cout << "Enter the value to insert: ";
                cin >> value;
                cout << "Enter the position to insert: ";
                cin >> position;
                head = Insert_Position(head, value, position);
                break;
            case 3:
                cout << "Enter the value to insert: ";
                cin >> value;
                head = Insert_End(head, value);
                break;
            case 4:
                cout << "Linked List: ";
                DisplayList(head);
                break;
            case 5:
                while (head != nullptr) {
                    Node* temp = head;
                    head = head->next;
                    delete temp;
                }
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

    } while (choice != 5);

    return 0;
}

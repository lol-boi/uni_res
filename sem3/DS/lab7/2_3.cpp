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

    if (position == 1 || head == nullptr){
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

Node* Delete_Beginning(Node* head) {
    if (head == nullptr) {
        cout << "Linked list is empty. Nothing to delete.\n";
        return nullptr;
    }

    Node* newHead = head->next;
    delete head;
    return newHead;
}

Node* Delete_Position(Node* head, int position) {
    if (head == nullptr) {
        cout << "Linked list is empty. Nothing to delete.\n";
        return nullptr;
    }

    if (position == 1) {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }

    Node* current = head;
    Node* prev = nullptr;
    int i = 1;

    while (i < position && current != nullptr) {
        prev = current;
        current = current->next;
        i++;
    }

    if (current == nullptr) {
        cout << "Invalid position. Node not found.\n";
        return head;
    }

    prev->next = current->next;
    delete current;
    return head;
}

Node* Delete_End(Node* head) {
    if (head == nullptr) {
        cout << "Linked list is empty. Nothing to delete.\n";
        return nullptr;
    }

    if (head->next == nullptr) {
        // Only one node in the list
        delete head;
        return nullptr;
    }

    Node* current = head;
    Node* prev = nullptr;

    while (current->next != nullptr) {
        prev = current;
        current = current->next;
    }

    prev->next = nullptr;
    delete current;
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
        // Display menu
        cout << "\nMenu:\n";
        cout << "1. Insert at the beginning\n";
        cout << "2. Insert at specified position\n";
        cout << "3. Delete from the beginning\n";
        cout << "4. Delete from specified position\n";
        cout << "5. Delete from the end\n";
        cout << "6. Display linked list\n";
        cout << "7. Exit\n";
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
                head = Delete_Beginning(head);
                break;
            case 4:
                cout << "Enter the position to delete: ";
                cin >> position;
                head = Delete_Position(head, position);
                break;
            case 5:
                head = Delete_End(head);
                break;
            case 6:
                cout << "Linked List: ";
                DisplayList(head);
                break;
            case 7:
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

    } while (choice != 7);

    return 0;
}

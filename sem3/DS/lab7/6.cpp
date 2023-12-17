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

Node* FindMiddle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head; // Empty list or single node
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
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
    int choice, value;

    do {
        // Display menu
        cout << "\nMenu:\n";
        cout << "1. Insert at the beginning\n";
        cout << "2. Find the middle node\n";
        cout << "3. Display linked list\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                head = Insert_Beginning(head, value);
                break;
            case 2:
                {
                    Node* middle = FindMiddle(head);
                    if (middle != nullptr) {
                        cout << "The middle node value is: " << middle->data << endl;
                    } else {
                        cout << "The list is empty or contains only one node.\n";
                    }
                }
                break;
            case 3:
                cout << "Linked List: ";
                DisplayList(head);
                break;
            case 4:
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

    } while (choice != 4);

    return 0;
}

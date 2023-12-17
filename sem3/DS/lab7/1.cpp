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

void display_ll(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int N;
    cout << "Enter the number of nodes (N): ";
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int value;
        cout << "Enter the value for node " << i + 1 << ": ";
        cin >> value;
        head = Insert_Beginning(head, value);
    }

    cout << "Linked List: ";
    display_ll(head);

    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    return 0;
}

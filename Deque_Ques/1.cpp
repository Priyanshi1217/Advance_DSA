#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class Deque {
    Node* front;
    Node* rear;

public:
    Deque() {
        front = rear = nullptr;
    }

    // Insert at front
    void insertFront(int value) {
        Node* newNode = new Node(value);

        if (front == nullptr) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    // Insert at rear
    void insertRear(int value) {
        Node* newNode = new Node(value);

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Delete from front
    void deleteFront() {
        if (front == nullptr) {
            cout << "Deque is empty\n";
            return;
        }

        Node* temp = front;

        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }

        delete temp;
    }

    // Delete from rear
    void deleteRear() {
        if (rear == nullptr) {
            cout << "Deque is empty\n";
            return;
        }

        Node* temp = rear;

        if (front == rear) {
            front = rear = nullptr;
        } else {
            rear = rear->prev;
            rear->next = nullptr;
        }

        delete temp;
    }

    // Display deque
    void display() {
        if (front == nullptr) {
            cout << "Deque is empty\n";
            return;
        }

        Node* temp = front;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    Deque dq;

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertFront(1);

    cout << "Deque: ";
    dq.display();

    dq.deleteFront();

    cout << "After deleting front: ";
    dq.display();

    dq.deleteRear();

    cout << "After deleting rear: ";
    dq.display();

    return 0;
}
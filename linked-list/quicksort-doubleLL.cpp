#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

Node* partition(Node* low, Node* high) {
    int pivot = high->data;
    Node* i = low->prev;

    for (Node* j = low; j != high; j = j->next) {
        if (j->data <= pivot) {
            i = (i == nullptr) ? low : i->next;
            swap(&(i->data), &(j->data));
        }
    }
    i = (i == nullptr) ? low : i->next;
    swap(&(i->data), &(high->data));
    return i;
}

void _quickSort(Node* low, Node* high) {
    if (high != nullptr && low != high && low != high->next) {
        Node* p = partition(low, high);
        _quickSort(low, p->prev);
        _quickSort(p->next, high);
    }
}

void quickSort(Node* head) {
    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    _quickSort(head, tail);
}

int main() {
    Node* head = new Node(5);
    head->next = new Node(20);
    head->next->prev = head;
    head->next->next = new Node(4);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(3);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(30);
    head->next->next->next->next->prev = head->next->next->next;

    cout << "Original List: ";
    printList(head);

    quickSort(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
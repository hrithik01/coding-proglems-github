#include <iostream>
#include <unordered_map>

using namespace std;

struct Node
{
    int val;
    Node *next;
    Node *random; // Pointer to a random node in the list
    Node(int val) : val(val), next(nullptr), random(nullptr) {}
};

Node *cloneList(Node *head)
{
    if (!head)
        return nullptr;

    // Step 1: Create a mapping from original nodes to their clones
    unordered_map<Node *, Node *> nodeMap;
    Node *current = head;

    // Create a clone for each node and store it in the map
    while (current)
    {
        nodeMap[current] = new Node(current->val);
        current = current->next;
    }

    // Step 2: Set the next and random pointers for the cloned nodes
    current = head;
    while (current)
    {
        nodeMap[current]->next = nodeMap[current->next];
        nodeMap[current]->random = nodeMap[current->random];
        current = current->next;
    }

    // Return the head of the cloned list
    return nodeMap[head];
}

void cleanMemory(Node *head)
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Create a sample linked list with random pointers
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Set random pointers
    head->random = head->next->next; // 1 -> 3
    head->next->random = head;       // 2 -> 1
    head->next->next->random = head->next->next->next; // 3 -> 4
    head->next->next->next->random = head->next; // 4 -> 2
    head->next->next->next->next->random = head->next->next; // 5 -> 3

    // Clone the linked list
    Node *clonedHead = cloneList(head);
    // Print the cloned list
    Node *current = clonedHead;
    while (current)
    {
        cout << "Value: " << current->val;
        if (current->random)
            cout << ", Random: " << current->random->val;
        else
            cout << ", Random: nullptr";
        cout << endl;
        current = current->next;
    }
    // Clean up memory
    cleanMemory(head);
    cleanMemory(clonedHead);
    return 0;
}
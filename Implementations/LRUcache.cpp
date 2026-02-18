#include <iostream>
#include <unordered_map>

using namespace std;

struct Node
{
    int key, val;
    Node *prev, *next;
    Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
};

class LRU
{
private:
    int capacity;
    unordered_map<int, Node *> cache;
    Node *head, *tail;

    void addFront(Node *node)
    {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    void removeNode(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void moveFront(Node *node)
    {
        removeNode(node);
        addFront(node);
    }

public:
    LRU(int n) : capacity(n)
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    // Destructor to clean up memory
    ~LRU()
    {
        Node *current = head;
        while (current)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
    int get(int key)
    {
        if (cache.find(key) == cache.end())
            return -1;
        Node *node = cache[key];
        moveFront(node);
        return node->val;
    }
    int put(int key, int val)
    {
        if (cache.find(key) != cache.end())
        {
            Node *node = cache[key];
            node->val = val;
            moveFront(node);
        }
        else
        {
            if (cache.size() == capacity)
            {
                Node *lruNode = tail->prev;
                removeNode(lruNode);
                cache.erase(lruNode->key);
                delete lruNode;
            }
            Node *node = new Node(key, val);
            cache[key] = node;
            addFront(node);
        }
    }
};

int main()
{
    LRU cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; // returns 1
    cache.put(3, 3);                // removes key 2
    cout << cache.get(2) << endl; // returns -1 (not found)
    cache.put(4, 4);                // removes key 1
    cout << cache.get(1) << endl; // returns -1 (not found)
    cout << cache.get(3) << endl; // returns 3
    cout << cache.get(4) << endl; // returns 4
    return 0;
}
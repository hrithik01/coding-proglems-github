#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void maxHeap() {
    // Max-heap with int
    priority_queue<int> maxHeap;

    // Insert elements
    maxHeap.push(3);
    maxHeap.push(1);
    maxHeap.push(5);
    maxHeap.push(2);

    // Print and remove elements
    cout << "Max-Heap with int: ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;

    return;
}

void minHeap() {
    // Min-heap with int
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Insert elements
    minHeap.push(3);
    minHeap.push(1);
    minHeap.push(5);
    minHeap.push(2);

    // Print and remove elements
    cout << "Min-Heap with int: ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
    return;
}

void maxHeapPair() {
    // Max-heap with pair<int, int>
    priority_queue<pair<int, int>> maxHeap;

    // Insert elements
    maxHeap.push({3, 100});
    maxHeap.push({1, 200});
    maxHeap.push({5, 300});
    maxHeap.push({2, 400});

    // Print and remove elements
    cout << "Max-Heap with pair<int, int>: ";
    while (!maxHeap.empty()) {
        cout << "(" << maxHeap.top().first << ", " << maxHeap.top().second << ") ";
        maxHeap.pop();
    }
    cout << endl;
    return;
}

void minHeapPair() {
    // Min-heap with pair<int, int>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    // Insert elements
    minHeap.push({3, 100});
    minHeap.push({1, 200});
    minHeap.push({5, 300});
    minHeap.push({2, 400});

    // Print and remove elements
    cout << "Min-Heap with pair<int, int>: ";
    while (!minHeap.empty()) {
        cout << "(" << minHeap.top().first << ", " << minHeap.top().second << ") ";
        minHeap.pop();
    }
    cout << endl;

    return;
}

// Custom comparator for max-heap
struct CustomMaxComparator {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first; // Max-heap based on the first element
    }
};
void maxHeapPairCustom() {
    // Max-heap with custom comparator
    priority_queue<pair<int, int>, vector<pair<int, int>>, CustomMaxComparator> customMaxHeap;

    // Insert elements
    customMaxHeap.push({3, 100});
    customMaxHeap.push({1, 200});
    customMaxHeap.push({5, 300});
    customMaxHeap.push({2, 400});

    // Print and remove elements
    cout << "Custom Max-Heap with pair<int, int>: ";
    while (!customMaxHeap.empty()) {
        cout << "(" << customMaxHeap.top().first << ", " << customMaxHeap.top().second << ") ";
        customMaxHeap.pop();
    }
    cout << endl;

    return;
}

// Custom comparator for min-heap
struct CustomMinComparator {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first; // Min-heap based on the first element
    }
};
void minHeapPairCustom() {
    // Min-heap with custom comparator
    priority_queue<pair<int, int>, vector<pair<int, int>>, CustomMinComparator> customMinHeap;

    // Insert elements
    customMinHeap.push({3, 100});
    customMinHeap.push({1, 200});
    customMinHeap.push({5, 300});
    customMinHeap.push({2, 400});

    // Print and remove elements
    cout << "Custom Min-Heap with pair<int, int>: ";
    while (!customMinHeap.empty()) {
        cout << "(" << customMinHeap.top().first << ", " << customMinHeap.top().second << ") ";
        customMinHeap.pop();
    }
    cout << endl;
    return;
}

int main () {
    maxHeap();
    minHeap();
    maxHeapPair();
    minHeapPair();
    maxHeapPairCustom();
    minHeapPairCustom();
    return 0;
}
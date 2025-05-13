## Comparator Function for Priority Queue

The comparator function for a priority queue should return `true` if the first element has **lower priority** than the second element. This means:

- For a max heap, the comparator should return true if the first element is less than the second element. (Max heap is the default behavior of `priority_queue` in C++, where the largest element has the highest priority.)
- For a min heap, the comparator should return true if the first element is greater than the second element. (In a min heap, the smallest element has the highest priority.)
- In C++, the priority_queue expects a comparator to be a functor (i.e., a class with an operator() method) rather than a standalone function.

```cpp
// For a max heap of pairs ordered by second element
struct CompareForMaxHeap {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        // Returns true if 'a' has lower priority than 'b'
        return a.second < b.second; 
    }
};

// Using this comparator creates a max heap based on the second element of the pair
// For example, given a vector of pairs {(1, 2), (3, 1), (4, 5)}
// The priority queue will order the pairs: (4, 5), (1, 2), (3, 1)
// The pair with the largest second element will be at the top
priority_queue<pair<int, int>, vector<pair<int, int>>, CompareForMaxHeap> maxHeapBySecond;

// For a min heap of pairs ordered by second element
struct CompareForMinHeap {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        // Returns true if 'a' has lower priority than 'b'
        return a.second > b.second; 
    }
};

// Using this comparator creates a min heap based on the second element of the pair
// For the same vector of pairs {(1, 2), (3, 1), (4, 5)}
// The priority queue will order the pairs: (3, 1), (1, 2), (4, 5)
// The pair with the smallest second element will be at the top
priority_queue<pair<int, int>, vector<pair<int, int>>, CompareForMinHeap> minHeapBySecond;

// To create a min heap ordered by first elements (then second elements as tiebreaker)
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
// For example, given {(1, 2), (3, 1), (4, 5), (1, 5)}, order would be: (1, 2), (1, 5), (3, 1), (4, 5)

// To create a max heap ordered by first elements (then second elements as tiebreaker)
priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> maxHeap;
// For example, given {(1, 2), (3, 1), (4, 5), (1, 5)}, order would be: (4, 5), (3, 1), (1, 5), (1, 2)
```

- To create a max heap for simple types, you can use the default behavior of `priority_queue` without providing a custom comparator.
```cpp
priority_queue<int> maxHeap; // Default max heap
```
- To create a min heap for simple types, you can use the `greater` comparator.
```cpp
priority_queue<int, vector<int>, greater<int>> minHeap; // Min heap
```

**Time complexity for priority queue operations with n elements:**
- Insertion: O(log n)
- Extraction: O(log n)
- Top element access: O(1)

## Stringstream and istringstream c++

stringstream is a stream class to operate on strings. It allows you to read from and write to strings as if they were streams.
```cpp
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    // Example of writing to a stringstream
    stringstream ss;
    ss << "Hello, ";
    ss << "world!";
    string output = ss.str(); // Convert the stream to a string
    cout << "Written to stringstream: " << output << endl;

    // Example of reading from a stringstream
    string input = "123 456 789";
    stringstream ss2(input);
    int num;
    cout << "Reading from stringstream: ";
    while (ss2 >> num) { // Extract integers from the stream
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
```
istringstream is a specialized version of stringstream that is used for reading from strings. It behaves like an input stream, allowing you to extract data from a string.

```cpp
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main() {
    string input = "123 456 789";
    istringstream iss(input);
    int num;
    cout << "Reading from istringstream: ";
    while (iss >> num) { // Extract integers from the stream
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
```

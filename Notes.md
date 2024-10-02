## Comparator Function for Priority Queue

The comparator function should return true if the first element should come after the second element in the priority queue. This means:

- For a max heap, the comparator should return true if the first element is less than the second element.
- For a min heap, the comparator should return true if the first element is greater than the second element.
- In C++, the priority_queue expects a comparator to be a functor (i.e., a class with an operator() method) rather than a standalone function.

```cpp
struct Compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }
};
priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
```
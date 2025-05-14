# Sets in C++

Sets are a type of associative container in C++ that store unique elements following a specific order. They are typically implemented as binary search trees.

## Traversing sets

### Using range-based for loop
- **Approach**: Use *range-based* loop to iterate through all elements in the set.
- **Time Complexity**: O(n), where n is the number of elements in the set.
- **Space Complexity**: O(1)
- **Example**:
```cpp
// Iterate over each element in the set
for (const auto& elem : mySet) {
    // Process the element
    std::cout << elem << " ";
}
```
- **Input**: {1, 2, 3}
- **Output**: 1 2 3

### Using iterators
- **Approach**: Use *iterators* to traverse the set explicitly.
- **Time Complexity**: O(n), where n is the number of elements in the set.
- **Space Complexity**: O(1)
- **Example**:
```cpp
// Traverse the set using an iterator
for (auto it = mySet.begin(); it != mySet.end(); ++it) {
    // Process the dereferenced iterator
    std::cout << *it << " ";
}
```
- **Input**: {'a', 'b', 'c'}
- **Output**: a b c

### Summary
- **Traversing a set** can be done efficiently with both range-based loops and iterators.
- **Both methods** offer *O(n)* time complexity and *O(1)* extra space.

## Ordered vs Unordered Sets

### Ordered Set (std::set)
- **Implementation**: Self-balancing **binary search tree** (e.g., Red-Black Tree)
- **Order**: Elements stored in **sorted** order
- **Time Complexity**:
  - `insert`, `erase`, `find`: O(log n)
  - Traversal: O(n)
- **Space Complexity**: O(n)
- **Use Cases**:
  - Maintaining a **sorted** collection
  - Performing **range queries** and order-based operations (`lower_bound`, `upper_bound`)
- **Cool Fact**: Supports in-order traversal via iterators to get elements in sorted order.

### Unordered Set (std::unordered_set)
- **Implementation**: **Hash table** with buckets and separate chaining
- **Order**: Elements stored in **no particular** order
- **Time Complexity**:
  - `insert`, `erase`, `find`: O(1) average, O(n) worst-case
  - Traversal: O(n)
- **Space Complexity**: O(n)
- **Use Cases**:
  - Fast **membership** tests and **deduplication**
  - When **order doesn't matter**
- **Cool Fact**: You can tune performance by adjusting the number of buckets with `reserve()` and controlling `max_load_factor()`.

### Choosing the Right Set
- Use **std::set** when:
  - You need elements in **sorted** order
  - You require **order-based** operations and range queries
- Use **std::unordered_set** when:
  - You need **constant-time** average complexity for inserts/lookups
  - The **order** of elements is **irrelevant**

### Summary of Complexities
| Operation       | std::set    | std::unordered_set           |
|-----------------|-------------|------------------------------|
| insert/erase    | O(log n)    | O(1) average, O(n) worst-case|
| find            | O(log n)    | O(1) average, O(n) worst-case|
| traversal       | O(n)        | O(n)                         |
| memory overhead | Moderate    | Higher (buckets and nodes)   |
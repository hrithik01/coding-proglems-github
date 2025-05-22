# Iterating Maps
## Iterator Method

- Basic iteration technique using iterators to access key-value pairs:

```cpp
map<string, int> myMap = {
    {"apple", 5},
    {"banana", 3},
    {"cherry", 7}
};

// Using iterator to traverse the map
for (map<string, int>::iterator it = myMap.begin(); it != myMap.end(); ++it) {
    cout << "Key: " << it->first << ", Value: " << it->second << endl;
}
```

## Auto Keyword (C++11 and later)

- Simplifies code by letting the compiler deduce the iterator type:

```cpp
map<string, int> myMap = {
    {"apple", 5},
    {"banana", 3},
    {"cherry", 7}
};

// Using auto keyword for cleaner syntax
for (auto it = myMap.begin(); it != myMap.end(); ++it) {
    cout << "Key: " << it->first << ", Value: " << it->second << endl;
}
```

## Range-based For Loop (C++11 and later)

- Even cleaner syntax that automatically iterates through all elements:

```cpp
map<string, int> myMap = {
    {"apple", 5},
    {"banana", 3},
    {"cherry", 7}
};

// Using range-based for loop
for (const auto& pair : myMap) {
    cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
}
```

## Structured Binding (C++17 and later)

- Direct access to the key and value components without using .first and .second:

```cpp
map<string, int> myMap = {
    {"apple", 5},
    {"banana", 3},
    {"cherry", 7}
};

// Using structured binding
for (const auto& [key, value] : myMap) {
    cout << "Key: " << key << ", Value: " << value << endl;
}
```

## Reverse Iteration

- Iterating through the map in reverse order:

```cpp
map<string, int> myMap = {
    {"apple", 5},
    {"banana", 3},
    {"cherry", 7}
};

// Iterating in reverse order
for (auto rit = myMap.rbegin(); rit != myMap.rend(); ++rit) {
    cout << "Key: " << rit->first << ", Value: " << rit->second << endl;
}
// the output will be:
// Key: cherry, Value: 7
// Key: banana, Value: 3
// Key: apple, Value: 5
```

## Iterating with while Loop

- Traditional while loop approach:

```cpp
map<string, int> myMap = {
    {"apple", 5},
    {"banana", 3},
    {"cherry", 7}
};

// Using while loop
auto it = myMap.begin();
while (it != myMap.end()) {
    cout << "Key: " << it->first << ", Value: " << it->second << endl;
    ++it;
}
```
# Comparing Maps
## Map Comparison Functions

A collection of utility functions for comparing ordered and unordered maps in C++.

## Template Functions for Map Comparison

- Generic implementation that works with both `map` and `unordered_map`:

```cpp
// Function to check if two maps are equal
template<typename MapType>
bool areEqual(const MapType& map1, const MapType& map2) {
    if (map1.size() != map2.size()) 
        return false;
    
    // Compare all elements manually
    for (const auto& [key, value] : map1) {
        auto it = map2.find(key);
        // If key not found or value is different
        if (it == map2.end() || it->second != value)
            return false;
    }
    return true;
}

// Function to check if smallerMap is a subset of largerMap
template<typename MapType>
bool isSubset(const MapType& smallerMap, const MapType& largerMap) {
    // Check each key-value pair in smaller map
    for (const auto& [key, value] : smallerMap) {
        auto it = largerMap.find(key);
        
        // If key not found or value is different
        if (it == largerMap.end() || it->second != value) 
            return false;
    }
    return true;
}
```

## Example Usage

- Using the functions with both ordered and unordered maps:

```cpp
// With ordered maps
map<string, int> orderedMap1 = {{"apple", 5}, {"banana", 3}, {"cherry", 7}};
map<string, int> orderedMap2 = {{"apple", 5}, {"banana", 3}, {"cherry", 7}};
map<string, int> orderedMap3 = {{"apple", 5}, {"banana", 3}};

// With unordered maps
unordered_map<string, int> unorderedMap1 = {{"apple", 5}, {"banana", 3}, {"cherry", 7}};
unordered_map<string, int> unorderedMap2 = {{"apple", 5}, {"banana", 3}};

// Testing equality
cout << "orderedMap1 equals orderedMap2: " 
     << (areEqual(orderedMap1, orderedMap2) ? "Yes" : "No") << endl;

// Testing subset relationship
cout << "orderedMap3 is subset of orderedMap1: " 
     << (isSubset(orderedMap3, orderedMap1) ? "Yes" : "No") << endl;

// Testing with unordered maps
cout << "unorderedMap2 is subset of unorderedMap1: " 
     << (isSubset(unorderedMap2, unorderedMap1) ? "Yes" : "No") << endl;
```

### Output:
```
orderedMap1 equals orderedMap2: Yes
orderedMap3 is subset of orderedMap1: Yes
unorderedMap2 is subset of unorderedMap1: Yes
```

## Comparing Maps of Different Types

- You can also compare between different map types:

```cpp
// Comparing between ordered and unordered maps
map<string, int> orderedMap = {{"apple", 5}, {"banana", 3}, {"cherry", 7}};
unordered_map<string, int> unorderedMap = {{"apple", 5}, {"banana", 3}};

// Check if unordered map is a subset of ordered map
bool isUnorderedSubset = isSubset(unorderedMap, orderedMap);  // Will be true
```

### Map Comparison Time and Space Complexity

- **areEqual function**: 
  - Time Complexity: O(n) for unordered_map, O(n log n) for map where n is the map size
  - Space Complexity: O(1), constant extra space

- **isSubset function**: 
  - Time Complexity: O(m) for unordered_map, O(m log n) for map where m is smaller map size
  - Space Complexity: O(1), constant extra space


## Ordered Map vs Unordered Map

### Key Characteristics

| Feature | `map` (Ordered) | `unordered_map` (Unordered) |
|---------|----------------|----------------------------|
| Implementation | Red-Black Tree | Hash Table |
| Order of elements | Sorted by keys | No defined order |
| Time Complexity (Average) | Insert: O(log n)<br>Access: O(log n)<br>Delete: O(log n) | Insert: O(1)<br>Access: O(1)<br>Delete: O(1) |
| Time Complexity (Worst) | Insert: O(log n)<br>Access: O(log n)<br>Delete: O(log n) | Insert: O(n)<br>Access: O(n)<br>Delete: O(n) |
| Space Complexity | O(n) | O(n) |
| Iterator Invalidation | Only for erased elements | Any insertion may invalidate all iterators |

### When to Use Each

- **Use `map` when:**
    - Order of elements matters (sorted by key)
    - Need guaranteed logarithmic time complexity
    - Working with custom comparison functions
    - Need stable iterator references after insertions/deletions

- **Use `unordered_map` when:**
    - Order doesn't matter
    - Need fastest average lookup time
    - Working with simple, hashable keys
    - Memory overhead of hash table is acceptable

### Example Usage

```cpp
// Ordered map example
map<string, int> orderedMap;
orderedMap["banana"] = 3;
orderedMap["apple"] = 5;
orderedMap["cherry"] = 7;

// Elements are automatically sorted by key
for (const auto& [key, value] : orderedMap) {
        cout << key << ": " << value << endl;
}
// Output will be:
// apple: 5
// banana: 3
// cherry: 7

// Unordered map example
unordered_map<string, int> unorderedMap;
unorderedMap["banana"] = 3;
unorderedMap["apple"] = 5;
unorderedMap["cherry"] = 7;

// Order is not guaranteed
for (const auto& [key, value] : unorderedMap) {
        cout << key << ": " << value << endl;
}
// Output could be any order, for example:
// banana: 3
// cherry: 7
// apple: 5
```

### Best Case Scenarios

- **`map` Best Case:** When you need to maintain sorted elements or perform range-based operations
- **`unordered_map` Best Case:** When you need extremely fast lookups and insertions with no sorting requirements

## Checking Unordered Map Equality and Subset

### Unordered Map Equality
- **Purpose**: Determine if two `unordered_map<string, int>` instances have identical key-value pairs.  
- **Approach**:  
    - Compare sizes first.  
    - Iterate through the first map and ensure each key exists in the second with the same value.

```cpp
// Function to check unordered_map equality
template<typename K, typename V>
bool areEqual(const unordered_map<K, V>& m1, const unordered_map<K, V>& m2) {
        // If sizes differ, maps can't be equal
        if (m1.size() != m2.size())
                return false;
        // Check every key-value in m1 against m2
        for (const auto& [key, value] : m1) {
                auto it = m2.find(key);
                // Missing key or different value → not equal
                if (it == m2.end() || it->second != value)
                        return false;
        }
        return true;
}
```

**Input Example**:
```cpp
unordered_map<string, int> mapA = {{"x", 1}, {"y", 2}, {"z", 3}};
unordered_map<string, int> mapB = {{"x", 1}, {"y", 2}, {"z", 3}};
```
**Output**:
```
areEqual(mapA, mapB) -> true
```

### Unordered Map Subset
- **Purpose**: Check if every key-value pair in one `unordered_map<string, int>` (the *subset*) exists in another (the *superset*).  
- **Approach**:  
    - Iterate through the smaller map.  
    - For each entry, verify presence and value match in the larger map.

```cpp
// Function to check unordered_map subset
template<typename K, typename V>
bool isSubset(const unordered_map<K, V>& smallMap, const unordered_map<K, V>& bigMap) {
        // Verify each key-value pair in smallMap
        for (const auto& [key, value] : smallMap) {
                auto it = bigMap.find(key);
                // Missing key or different value → not a subset
                if (it == bigMap.end() || it->second != value)
                        return false;
        }
        return true;
}
// If value is integer, you can also use this function
bool isSubset(const unordered_map<char, int>& mpt, const unordered_map<char, int>& mps) {
        for (const auto& [key, value] : mpt) {
                auto it = mps.find(key);
                // Missing key or less value → not a subset
                if (it == mps.end() || it->second < value)
                        return false;
        }
        return true;
}
```

**Input Example**:
```cpp
unordered_map<string, int> mapC = {{"x", 1}, {"y", 2}};
unordered_map<string, int> mapD = {{"x", 1}, {"y", 2}, {"z", 3}};
```
**Output**:
```
isSubset(mapC, mapD) -> true
```

## Complexity Analysis
- **areEqual**  
    - Time Complexity: *O(n)* on average, where *n* is the number of elements.  
    - Space Complexity: *O(1)* extra space.
- **isSubset**  
    - Time Complexity: *O(m)* on average, where *m* is the size of the smaller map.  
    - Space Complexity: *O(1)* extra space.

## Maps can also store functors and function pointers
- Maps can be used to store function pointers or functors, allowing for dynamic dispatch based on keys.
- This is useful for implementing command patterns or dispatch tables.

```cpp
// map each operator string to the corresponding lambda
unordered_map<string, function<int(int,int)>> ops = {
    { "+", [](int a, int b) { return a + b; } },
    { "-", [](int a, int b) { return a - b; } },
    { "*", [](int a, int b) { return a * b; } },
    { "/", [](int a, int b) { return a / b; } }
};

// applies the operator named by 'op' to operands a and b
int applyOp(const string& op, int a, int b) {
    // look up the operator in the map (O(1) average)
    auto it = ops.find(op);
    if (it != ops.end()) {
        return it->second(a, b);
    }
    throw invalid_argument("Unsupported operator: " + op);
}
// Example usage
int main() {
    int a = 10, b = 5;
    cout << applyOp("+", a, b) << endl; // Output: 15
    cout << applyOp("-", a, b) << endl; // Output: 5
    cout << applyOp("*", a, b) << endl; // Output: 50
    cout << applyOp("/", a, b) << endl; // Output: 2
}
```
## `<int(int,int)>` Template Parameter
- **Definition**: Template parameter for `std::function`.  
- **Description**: A callable that takes two `int` arguments and returns an `int`. *Think of it as a type alias for such callables.*

## `[]` Lambda Capture Clause
- **Clause**: `[]` (placed before the parameter list `(int a, int b)`)  
- **Meaning**: *Capture nothing* from the surrounding scope.  
- **Details**:  
    - Introduces an anonymous function (lambda) with parameters `(int a, int b)` and body `{ return a + b; }`.  
    - To capture local variables, modify the clause (e.g., `[x]` or `[&]`).

```cpp
// Example: std::function using <int(int,int)> and empty capture lambda
std::function<int(int,int)> addFunc = [](int a, int b) { return a + b; };
```
# `move` in C++

## Overview
`move` is a utility function in the C++ Standard Library that casts an object to an rvalue reference, enabling move semantics.

## Purpose
- Allows the efficient transfer of resources from one object to another
- Avoids unnecessary copying of data
- Used when an object is no longer needed in its original location

## Syntax
```cpp
template <typename T>
typename remove_reference<T>::type&& move(T&& t) noexcept;
```

## How It Works
- `move` doesn't actually move anything by itself
- It simply casts its argument to an rvalue reference
- This enables the move constructor or move assignment operator to be called
- The actual moving is performed by the move constructor/assignment operator

## Examples

### Example 1: Moving a Vector
```cpp
vector<int> source = {1, 2, 3, 4, 5};
// Before move: source contains data
vector<int> destination = move(source);
// After move: destination contains data, source is empty

// Input: source = {1, 2, 3, 4, 5}, destination = {}
// Output: source = {}, destination = {1, 2, 3, 4, 5}
```

### Example 2: Moving a String
```cpp
string str1 = "Hello, World!";
// str1 owns its data
string str2 = move(str1);
// str2 now owns the data, str1 is in a valid but unspecified state

// Input: str1 = "Hello, World!", str2 = ""
// Output: str2 = "Hello, World!", str1 = "" (possibly)
```
### Example 3: Pushing Elements into a Vector

```cpp
// Create a vector of unique_ptr objects
vector<unique_ptr<int>> source;
source.push_back(make_unique<int>(10));
source.push_back(make_unique<int>(20));
source.push_back(make_unique<int>(30));

// Create destination vector
vector<unique_ptr<int>> destination;

// Push elements from source to destination using move
for (auto& ptr : source) {
    // Without move, this wouldn't compile since unique_ptr can't be copied
    destination.push_back(move(ptr));
    // After move, ptr is now nullptr
}

// Input: source = {unique_ptr(10), unique_ptr(20), unique_ptr(30)}, destination = {}
// Output: source = {nullptr, nullptr, nullptr}, destination = {unique_ptr(10), unique_ptr(20), unique_ptr(30)}
```

## Best Practices
- Don't use the object after it's been moved from
- Use `move` for rvalue references to enable move semantics
- Consider using `forward` instead for perfect forwarding
- Remember that moved-from objects must still be in a valid state

## Note for move
### Best Use Cases for `std::move`

- **Large Containers**: For objects like `std::vector` or `std::string` where copying could involve allocating new memory and copying many elements.
- **Resource-Managing Classes**: For classes like `std::unique_ptr` where ownership can be transferred without duplicating resources.
- **Custom Types**: When you implement move constructors/assignment operators for custom classes to optimize performance.

### Why It's Redundant for Integers

- **Trivial Type**: Integers (and other primitive types) are trivially copyable, making both copy and move operations have similar (minimal) cost.
- **No Resource Ownership**: They don't manage resources, so there's no benefit in "moving" them.

In your code, since `int` is trivial to copy, using `std::move` adds unnecessary complexity without improving performance.
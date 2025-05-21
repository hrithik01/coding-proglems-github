# Lambda Functions in C++

Lambda functions are *anonymous* function objects you can define **inline**. They capture variables from surrounding scope, offering concise syntax for callbacks, STL algorithms, and more.

## Syntax
```cpp
[capture](parameters) mutable(optional) -> return_type {
    // function body
}
```
- **capture**: Specifies how external variables are captured (`[]`, `[=]`, `[&]`, or mixed).
- **parameters**: Function parameters, like in a normal function.
- **mutable**: Allows modification of captured variables when they are captured by value.
- **return_type**: (Optional) Explicit return type if not deduced.

## 1. Capture by Value [=]
- **Approach**: Copies external variables into the lambda. *Safe* against changes after creation.
- Captured variables are **read-only** unless `mutable` is used.

### Example
```cpp
int x = 10;
auto f = [=]() {
    // x is copied, original x unchanged
    std::cout << "Inside lambda, x = " << x << std::endl;
};
x = 20;
f();  // Output: Inside lambda, x = 10
```
**Input**: x = 10 (then modified to 20)  
**Output**: Inside lambda, x = 10

## 2. Capture by Reference [&]
- **Approach**: Captures external variables by reference. Allows reading and modifying the original.

### Example
```cpp
int x = 5;
auto g = [&]() {
    x += 3;  // Modifies outer x
    std::cout << "Inside lambda, x = " << x << std::endl;
};
g();               // Output: Inside lambda, x = 8
std::cout << x;    // Output: 8
```
**Input**: x = 5  
**Output**: Inside lambda, x = 8; 8

## 3. Mixed Captures
- **Approach**: Combine *value* and *reference* captures for different variables.

### Example
```cpp
int a = 1, b = 2;
auto h = [=, &b]() mutable {
    a = 10;    // modifies local copy only
    b = 20;    // modifies outer b
    std::cout << "a=" << a << ", b=" << b << std::endl;
};
h();                 // Output: a=10, b=20
std::cout << a << b; // Output: 1 20
```
**Input**: a=1, b=2  
**Output**: a=10, b=20; 1 20

## 4. Default and Explicit Captures
- `[=]` captures all external variables by value.
- `[&]` captures all by reference.
- `[this]` captures the `this` pointer in a member function.
- `[&, x]` captures `x` by value, others by reference.
- `[=, &y]` captures `y` by reference, others by value.

### Example: Capture this
```cpp
struct Counter {
    int count = 0;
    void inc() {
        auto incr = [this]() { ++count; };
        incr();
    }
};
Counter c;
c.inc();
std::cout << c.count;  // Output: 1
```
**Input**: initial count=0  
**Output**: 1

## 5. Mutable Lambdas
- By default, lambdas with value captures are **const**. To modify captured copies, use `mutable` keyword.

### Example
```cpp
int x = 3;
auto m = [=]() mutable {
    x += 5;
    std::cout << "Inside mutable lambda, x=" << x << std::endl;
};
m();                // Output: x=8
std::cout << x;     // Output: 3 (outer x unchanged)
```

## 6. Lambdas in STL Algorithms
```cpp
std::vector<int> v = {1,2,3,4,5};
// Count even numbers
int evens = std::count_if(v.begin(), v.end(), [](int n) { return n%2==0; });
std::cout << evens;  // Output: 2
```

## Cool Facts
- **Zero-overhead**: Optimized like inline functions; little to no runtime cost.
- **Generic lambdas**: Use `auto` in parameter list (C++14) to create templated lambdas.
  ```cpp
auto gen = [](auto x, auto y) { return x+y; };
std::cout << gen(1,2) << gen(1.5, 2.5);
```  
- **Stateful**: Captures allow lambdas to carry state, unlike plain functions.

## Summary
- **Lambda functions** provide an inline, concise way to define function objects.
- Capture lists (`[]`, `[=]`, `[&]`) control **value** vs. **reference** captures.
- Use `mutable` to allow modification of captured-by-value copies.
- Widely used in **STL** algorithms, callbacks, and event handlers.

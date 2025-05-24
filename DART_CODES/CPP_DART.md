# CPP_DART.md

## C++ vs Dart Syntax Comparison

### 1. Arrays and Lists
**C++:**
```cpp
vector<int> arr = {1, 2, 3};
arr.push_back(4);
```
**Dart:**
```dart
List<int> arr = [1, 2, 3];
arr.add(4);
```

### 2. Sorting
**C++:**
```cpp
sort(arr.begin(), arr.end());
```
**Dart:**
```dart
arr.sort();
```

### 3. Maps
**C++:**
```cpp
unordered_map<int, string> mp;
mp[1] = "one";
```
**Dart:**
```dart
Map<int, String> mp = {};
mp[1] = "one";
```

### 4. Sets
**C++:**
```cpp
set<int> s;
s.insert(5);
```
**Dart:**
```dart
Set<int> s = {};
s.add(5);
```

### 5. Vectors/Lists
**C++:**
```cpp
vector<int> v;
v.push_back(10);
```
**Dart:**
```dart
List<int> v = [];
v.add(10);
```

### 6. Stacks
**C++:**
```cpp
stack<int> st;
st.push(1);
st.pop();
```
**Dart:**
```dart
List<int> st = [];
st.add(1); // push
st.removeLast(); // pop
```

### 7. Queues
**C++:**
```cpp
queue<int> q;
q.push(1);
q.pop();
```
**Dart:**
```dart
List<int> q = [];
q.add(1); // enqueue
q.removeAt(0); // dequeue
```

### 8. Data Types
**C++:**
```cpp
int a = 5;
double b = 3.14;
string s = "hi";
```
**Dart:**
```dart
int a = 5;
double b = 3.14;
String s = "hi";
```

### 9. Strings
**C++:**
```cpp
string s = "hello";
s += " world";
```
**Dart:**
```dart
String s = "hello";
s += " world";
```

### 10. Lambdas/Anonymous Functions
**C++:**
```cpp
auto add = [](int a, int b) { return a + b; };
```
**Dart:**
```dart
var add = (int a, int b) => a + b;
```

### 11. Functions
**C++:**
```cpp
int add(int a, int b) {
    return a + b;
}
```
**Dart:**
```dart
int add(int a, int b) {
  return a + b;
}
```

### 12. Classes and Objects
**C++:**
```cpp
class Person {
public:
    int age;
    Person(int a) : age(a) {}
};
Person p(25);
```
**Dart:**
```dart
class Person {
  int age;
  Person(this.age);
}
var p = Person(25);
```

### 13. Inbuilt Sort
**C++:**
```cpp
sort(arr.begin(), arr.end());
```
**Dart:**
```dart
arr.sort();
```

### 14. Main Function
**C++:**
```cpp
int main() {
    // code
    return 0;
}
```
**Dart:**
```dart
void main() {
  // code
}
```

---

This document provides a quick reference for converting C++ code to Dart, focusing on syntax similarities and differences. For more details, refer to the converted files in this project.

### 15. Substrings
**C++:**
```cpp
string s = "Hello, World!";
string sub = s.substr(7, 5); // "World"
```
**Dart:**
```dart
String s = "Hello, World!";
String sub = s.substring(7, 12); // "World"
```

### 16. Characters & Runes
**C++ (char):**
```cpp
char c = 'A';
int code = int(c); // 65
```
**Dart (runes & codeUnits):**
```dart
String s = "A";
int code = s.runes.first;        // 65
List<int> codes = s.codeUnits;   // [65]
```

### 17. Other Cool Inbuilt Features

**String Interpolation & Multiline:**
```dart
String name = "Dart";
print("Hello, $name!");           // Hello, Dart!
String multi = """
Line1
Line2
""";
```

**Null-aware Operators:**
```dart
String? maybe;
print(maybe ?? "default");        // "default"
int? len = maybe?.length;         // null
```

**Cascade Notation:**
```dart
class Builder {
  int x = 0;
  void setX(int v) => x = v;
}
var b = Builder()..setX(10)..setX(20);
```

**Collection if & Spread:**
```dart
var list = [1, 2, 3];
var newList = [0, if (list.isNotEmpty) ...list];
```


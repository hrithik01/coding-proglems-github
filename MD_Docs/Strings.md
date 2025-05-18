## C++ Strings Overview

**`std::string`** is a dynamic, mutable sequence of characters. It manages its own memory and offers rich member functions for common tasks.

### Basic Operations
- **Creation**:
  ```cpp
  string s1;              // empty
  string s2("hello");   // from literal
  string s3(s2);          // copy
  string s4(5, 'a');      // "aaaaa"
  ```
- **Properties**:
  - `s.size()` / `s.length()` → number of characters
  - `s.empty()` → true if size == 0
- **Access**:
  - `s[i]` or `s.at(i)` → character at index _i_
  - `s.front()`, `s.back()` → first/last character

### Traversal
- **Index-based**:
  ```cpp
  for (size_t i = 0; i < s.size(); i++) {
      char c = s[i];
      // ...
  }
  ```
- **Range-based**:
  ```cpp
  for (char c : s) {
      // ...
  }
  ```
- **Iterators**:
  ```cpp
  for (auto it = s.begin(); it != s.end(); ++it) {
      // *it
  }
  ```

### Concatenation
- **`+` operator**: `s = s1 + s2;`
- **`+=` operator**: `s1 += s2;`
- **`append` method**:
  ```cpp
  s.append(" world");
  ```

### Substring and Slicing
- **`substr(pos, len)`**:
  ```cpp
  string s = "abcdef";
  string t = s.substr(2, 3); // "cde"
  ```

### Searching and Finding
- **`find(str, pos)`** → index or `npos`
- **`rfind`**, **`find_first_of`**, **`find_last_of`**
- **Example**:
  ```cpp
  if (s.find("lo") != string::npos) {
      // found
  }
  ```

### Modification
- **`insert(pos, str)`** → insert substring
- **`erase(pos, len)`** → remove substring
- **`replace(pos, len, str)`** → overwrite

### Conversions
- **`to_string`**: numeric → string
- **`stoi`, `stol`, `stoll`**: string → integer
- **`c_str()`**: `const char*` for C APIs

---

## `stringstream` and Related Classes
Include `<sstream>` for **`stringstream`**, **`istringstream`**, **`ostringstream`**. They treat strings as streams.

### Writing to a Stream (`<<`)
```cpp
ostringstream oss;
oss << "Value: " << 42;
string out = oss.str(); // "Value: 42"
```

### Reading from a Stream (`>>`)
```cpp
istringstream iss("10 20 30");
int x;
while (iss >> x) {
    // parse each number
}
```

---

## `getline` vs `>>`
- **`getline(cin, line)`** reads an entire line, including spaces, until `'\n'`.
- **`cin >> word`** reads a token until whitespace and stops.

```cpp
string line;
getline(cin, line);      // full line
istringstream iss(line);
string word;
while (iss >> word) {
    // splits by spaces
}
```

---

## Parsing with Custom Delimiter
```cpp
string path = "usr/local/bin/env";
istringstream pathStream(path);
string segment;

// Use getline with '/' delimiter to split path into folders
while (getline(pathStream, segment, '/')) {
    cout << segment << '\n';
}
// Output:
// usr
// local
// bin
// env
```

---

## Cool Facts
- *Small String Optimization (SSO)*: many STL implementations store small strings in-place (no heap alloc).
- `std::string` uses contiguous storage; you can get pointer via `&s[0]`.
- Modifying a string may invalidate iterators and references.
- C++20 adds **`starts_with`** and **`ends_with`** for `std::string`.

*This cheat sheet covers the essentials for working with strings in C++. Happy coding!*
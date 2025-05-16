## Character Frequency Mapping with Vectors

When you need to store counts or frequencies of alphabetical characters in C++, you can use a `vector` with an appropriate size:

### ASCII Ranges for Alphabets
- **Uppercase 'A' to 'Z'**: ASCII codes **65** to **90**
- **Lowercase 'a' to 'z'**: ASCII codes **97** to **122**

### 1. Lowercase Only (26 elements)
```cpp
vector<int> freq(26, 0);
// For each character ch in your string:
int idx = ch - 'a';    // 'a' -> 0, 'b' -> 1, ..., 'z' -> 25
freq[idx]++;
```

### 2. Uppercase Only (26 elements)
```cpp
vector<int> freq(26, 0);
// For each character ch in your string:
int idx = ch - 'A';    // 'A' -> 0, 'B' -> 1, ..., 'Z' -> 25
freq[idx]++;
```

### 3. Both Uppercase and Lowercase (52 elements)
```cpp
vector<int> freq(52, 0);
for (char ch : input) {
    int idx;
    if (ch >= 'A' && ch <= 'Z') {
        idx = ch - 'A';          // indexes 0..25 for 'A'..'Z'
    } else if (ch >= 'a' && ch <= 'z') {
        idx = 26 + (ch - 'a');   // indexes 26..51 for 'a'..'z'
    } else {
        continue;                // skip non-alphabetic characters
    }
    freq[idx]++;
}
```

### 4. Using a Full ASCII-Sized Vector (128 elements)
If you need to handle any ASCII character (including punctuation, digits, etc.), you can allocate a vector of size 128:
```cpp
vector<int> freq(128, 0);
for (char ch : input) {
    freq[static_cast<unsigned char>(ch)]++;
}
```

### Why Not Just Subtract 'a' for All Characters?
- Subtracting `'a'` from a lowercase letter (`'a'..'z'`) yields `0..25`.  
- Subtracting `'a'` from an uppercase letter (`'A'..'Z'`) yields negative values (`65 - 97 = -32`, etc.), which are invalid indices.

### Input/Output Example
- **Input**: "aAbBzZ"
- **Frequency Vector (52 elements)**:
  - Index `0`  (`'A'`) count = 1
  - Index `26` (`'a'`) count = 1
  - Index `1`  (`'B'`) count = 1
  - Index `27` (`'b'`) count = 1
  - Index `25` (`'Z'`) count = 1
  - Index `51` (`'z'`) count = 1

---

*This document explains how to choose vector sizes and mapping logic to efficiently store and update character frequencies for different use cases.*
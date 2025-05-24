// DART_CODES/arrays-strings/ants-sweets.dart
// Converted from C++
// Logic and comments preserved

List<int> sweet(List<int> s) {
  int n = s.length;
  List<int> swts = List.filled(n, 0);
  List<int> ans = List.filled(n, 0);
  for (int i = 0; i < n; i++) {
    swts[i] = n;
    for (int j = 0; j < i; j++) swts[j]--;
    for (int j = 0; j <= i; j++) {
      if (swts[j] > n - s[i]) ans[j] = 1;
    }
  }
  return ans;
}

void main() {
  // No example in original C++ main
}

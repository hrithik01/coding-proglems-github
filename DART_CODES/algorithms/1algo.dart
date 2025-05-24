// DART_CODES/algorithms/1algo.dart
// Converted from C++
// Logic and comments preserved

int frogJump2(List<int> stones) {
  int ans = 0, n = stones.length;
  for (int i = 2; i < n; i++) {
    ans = (ans > (stones[i] - stones[i - 2])) ? ans : (stones[i] - stones[i - 2]);
  }
  return ans;
}

void main() {
  List<int> stones = [0, 3, 5, 9, 12, 15, 17];
  print(frogJump2(stones));
}

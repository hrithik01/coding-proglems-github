// DART_CODES/backtracking-graphs-subsets/n-queens.dart
// Converted from C++
// Logic and comments preserved

class Sol {
  bool safe(List<List<int>> ans, int row, int col, int n) {
    // dir1
    for (int i = 0; i < col; i++) {
      if (ans[row][i] != 0) return false;
    }
    // dir2
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
      if (ans[i][j] != 0) return false;
    }
    // dir3
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
      if (ans[i][j] != 0) return false;
    }
    return true;
  }

  void solve(List<List<int>> res, List<List<int>> ans, int col, int n) {
    if (col == n) {
      for (int i = 0; i < n; i++) res[i] = List.from(ans[i]);
      return;
    }
    for (int i = 0; i < n; i++) {
      if (safe(ans, i, col, n)) {
        ans[i][col] = 1;
        solve(res, ans, col + 1, n);
        ans[i][col] = 0;
      }
    }
  }

  List<List<int>> nQueen(int n) {
    List<List<int>> ans = List.generate(n, (_) => List.filled(n, 0));
    List<List<int>> res = List.generate(n, (_) => List.filled(n, 0));
    solve(res, ans, 0, n);
    return res;
  }

  void print(List<List<int>> v) {
    for (var vi in v) {
      print(vi.join(' '));
    }
  }
}

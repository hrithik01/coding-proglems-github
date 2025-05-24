// DART_CODES/backtracking-graphs-subsets/knight-tour.dart
// Converted from C++
// Logic and comments preserved

class Solution {
  List<List<int>> knightTour(int n) {
    List<List<int>> res = List.generate(n, (_) => List.filled(n, -1));
    List<List<int>> moves = [
      [-2, -1], [-2, 1], [2, -1], [2, 1],
      [-1, -2], [-1, 2], [1, -2], [1, 2]
    ];
    if (dfs(res, 0, 0, 1, n, moves)) {
      return res;
    }
    return [];
  }

  bool dfs(List<List<int>> res, int x, int y, int count, int n, List<List<int>> moves) {
    if (x < 0 || x >= n || y < 0 || y >= n || res[x][y] != -1) {
      return false;
    }
    res[x][y] = count;
    if (count == n * n) {
      return true;
    }
    for (var move in moves) {
      if (dfs(res, x + move[0], y + move[1], count + 1, n, moves)) {
        return true;
      }
    }
    res[x][y] = -1;
    return false;
  }
}

void main() {
  print("Hello From Hrithik\n");
  Solution s = Solution();
  List<List<int>> res = s.knightTour(7);
  for (var row in res) {
    print(row.join(' '));
  }
}

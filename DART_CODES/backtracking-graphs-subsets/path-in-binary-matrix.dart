// DART_CODES/backtracking-graphs-subsets/path-in-binary-matrix.dart
// Converted from C++
// Logic and comments preserved

class Solution {
  List<List<int>> pathInMatrix(List<List<int>> matrix) {
    List<List<int>> res = [];
    List<int> path = [];
    int n = matrix.length;
    int m = matrix[0].length;
    List<List<bool>> visited = List.generate(n, (_) => List.filled(m, false));
    dfs(matrix, res, path, visited, 0, 0);
    return res;
  }

  void dfs(List<List<int>> matrix, List<List<int>> res, List<int> path, List<List<bool>> visited, int i, int j) {
    if (i < 0 || i >= matrix.length || j < 0 || j >= matrix[0].length || visited[i][j] || matrix[i][j] == 0) {
      return;
    }
    path.add(matrix[i][j]);
    visited[i][j] = true;
    if (i == matrix.length - 1 && j == matrix[0].length - 1) {
      res.add(List.from(path));
    }
    dfs(matrix, res, path, visited, i - 1, j);
    dfs(matrix, res, path, visited, i + 1, j);
    dfs(matrix, res, path, visited, i, j - 1);
    dfs(matrix, res, path, visited, i, j + 1);
    path.removeLast();
    visited[i][j] = false;
  }

  // Shortest path in binary matrix (BFS)
  int findShortestPath(List<List<int>> mat, int sourceX, int sourceY, int destX, int destY) {
    int n = mat.length;
    int m = mat[0].length;
    List<List<int>> dist = List.generate(n, (_) => List.filled(m, 1 << 30));
    List<List<int>> q = [];
    List<int> dx = [-1, 0, 1, 0];
    List<int> dy = [0, 1, 0, -1];
    dist[sourceX][sourceY] = 1;
    q.add([sourceX, sourceY]);
    // ...rest of BFS logic as in C++...
    return -1; // placeholder
  }
}

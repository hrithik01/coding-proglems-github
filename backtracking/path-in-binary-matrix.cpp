#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> pathInMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        vector<int> path;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        dfs(matrix, res, path, visited, 0, 0);
        return res;
    }

    void dfs(vector<vector<int>>& matrix, vector<vector<int>>& res, vector<int>& path, vector<vector<bool>>& visited, int i, int j) {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || visited[i][j] || matrix[i][j] == 0) {
            return;
        }
        path.push_back(matrix[i][j]);
        visited[i][j] = true;
        if (i == matrix.size() - 1 && j == matrix[0].size() - 1) {
            res.push_back(path);
        }
        dfs(matrix, res, path, visited, i - 1, j);
        dfs(matrix, res, path, visited, i + 1, j);
        dfs(matrix, res, path, visited, i, j - 1);
        dfs(matrix, res, path, visited, i, j + 1);
        path.pop_back();
        visited[i][j] = false;
    }

};

int main() {
    vector<vector<int>> matrix = {
        {1, 9, 9, 9},
        {1, 2, 0, 1},
        {0, 3, 4, 0},
        {0, 0, 5, 6}
    };
    Solution sol;
    vector<vector<int>> res = sol.pathInMatrix(matrix);
    for (auto path : res) {
        for (int i : path) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
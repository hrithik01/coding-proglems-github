#include <iostream>
#include <vector>
#include <queue>

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

// Shortest path in binary matrix
// Given a n x n binary matrix, find the shortest path length from (0, 0) to (n - 1, n - 1)
// Below approach is using BFS instead of DFS which is more efficient for shortest path
int findShortestPath(vector<vector<int>>& mat, int sourceX, int sourceY, int destX, int destY) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    queue<pair<int, int>> q;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    dist[sourceX][sourceY] = 1;
    q.push({sourceX, sourceY});

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newX = curr.first + dx[i];
            int newY = curr.second + dy[i];

            if (newX >= 0 && newX < n && newY >= 0 && newY < m && mat[newX][newY] && dist[newX][newY] == INT_MAX) {
                dist[newX][newY] = dist[curr.first][curr.second] + 1;
                q.push({newX, newY});
            }
        }
    }

    if (dist[destX][destY] == INT_MAX) return -1;
    return dist[destX][destY];
}

// Shortest path in binary matrix using DFS more like brute force and backtracking
// This is not efficient as BFS
void dfs(vector<vector<int>>& mat, vector<vector<bool>>& vis, int i, int j, int& res, int& pathLen, int destX, int destY ) {
    if(i<0 || j<0 || i>=mat.size() || j>= mat[0].size() || mat[i][j]==0 || vis[i][j] == 1) return;
    vis[i][j] = 1;
    pathLen++;
    if(i == destX && j == destY) res = min(res, pathLen);
    dfs(mat, vis, i+1, j, res, pathLen, destX, destY);
    dfs(mat, vis, i-1, j, res, pathLen, destX, destY);
    dfs(mat, vis, i, j+1, res, pathLen, destX, destY);
    dfs(mat, vis, i, j-1, res, pathLen, destX, destY);
    pathLen--;
    vis[i][j] = 0;
}

int findShortestPathDFS(vector<vector<int>>& mat, 
                        int sourceX, int sourceY,  
                        int destX, int destY,  
                        int n, int m)
{
    int res = INT_MAX;
    int pathLen = 0;
    vector<vector<bool>> vis(mat.size(), vector<bool>(mat[0].size(), 0));
    dfs(mat, vis, sourceX, sourceY, res, pathLen, destX, destY);
    if(res == INT_MAX) return -1;
    return res;
}
int main() {
    vector<vector<int>> matrix = {
        {1, 9, 9, 9},
        {1, 2, 0, 1},
        {0, 3, 4, 0},
        {0, 0, 5, 6}
    };

    Solution sol;
    vector<vector<int>> res = sol.pathInMatrix(matrix);

    int shortestPathUsingDFS = findShortestPathDFS(matrix, 0, 0, matrix.size()-1, matrix[0].size()-1, matrix.size(), matrix[0].size());
    int shortestPathUsingBFS = findShortestPath(matrix, 0, 0, matrix.size()-1, matrix[0].size()-1);

    cout << "Shortest path using DFS: " << shortestPathUsingDFS << endl;
    cout << "Shortest path using BFS: " << shortestPathUsingBFS << endl;

    for (auto path : res) {
        for (int i : path) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
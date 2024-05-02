#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

bool is_safe(int x, int y, int n, int m) {
 return x>=0 && y>=0 && x<n && y<m;   
}

void dfs(vector<vector<char>>& grid, vector<vector<bool>>& vis, int x, int y, string word, int idx, bool& found, vector<pair<int, int>>& res) {
    if (idx == word.size()) {
        found = true;
        return;
    }
    if (is_safe(x, y, grid.size(), grid[0].size()) && !vis[x][y] && grid[x][y] == word[idx]) {
        vis[x][y] = true;
        res.push_back({x, y});
        dfs(grid, vis, x + 1, y, word, idx + 1, found, res);
        dfs(grid, vis, x - 1, y, word, idx + 1, found, res);
        dfs(grid, vis, x, y + 1, word, idx + 1, found, res);
        dfs(grid, vis, x, y - 1, word, idx + 1, found, res);
        vis[x][y] = false;
    }
}

// Apply backtracking on every element to search the required word
bool WordSearch(vector<vector<char>> grid, string word, vector<pair<int, int>>& res){
  int n = grid.size();
  int m = grid[0].size();

  vector<vector<bool>> vis(n, vector<bool>(m, false));

  bool found = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == word[0]) {
                dfs(grid, vis, i, j, word, 0, found, res);
                if (found) return true;
            }
        }
    }
  return false;
}

int main() {
    cout<<"Hello from hrithik \n";
    vector<vector<char>> grid = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";
    vector<pair<int, int>> res;
    cout << WordSearch(grid, word, res) << endl;
    for (auto p : res) {
        cout <<"{ "<<p.first << " " << p.second<<" } ";
    }
    cout<<endl;
    return 0;
}

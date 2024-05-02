#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> knightTour(int n) {
        vector<vector<int>> res(n, vector<int>(n, -1));
        vector<pair<int, int>> moves = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};
        if (dfs(res, 0, 0, 1, n, moves)) {
            return res;
        }
        return {};
    }

    bool dfs(vector<vector<int>>& res, int x, int y, int count, int n, vector<pair<int, int>>& moves) {
        if(x < 0 || x >= n || y < 0 || y >= n || res[x][y] != -1) {
            return false;
        }
        res[x][y] = count;
        if (count == n * n) {
            return true;
        }
        for (auto move : moves) {
            if (dfs(res, x + move.first, y + move.second, count + 1, n, moves)) {
                return true;
            }
        }
        res[x][y] = -1;
        return false;
    }
};

int main() {
    cout<<"Hello From Hrithik \n";
    Solution s;
    vector<vector<int>> res = s.knightTour(7);
    for (auto row : res) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    return 0;
}
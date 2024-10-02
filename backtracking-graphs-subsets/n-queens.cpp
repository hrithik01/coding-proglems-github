#include <iostream>
#include <vector>

using namespace std;

class Sol {
    public:
        bool safe(vector<vector<int>>& ans, int row, int col, int n) {
            // dir1
            for(int i=0; i<col; i++) {
                if(ans[row][i]) return false;
            }
            // dir2
            for(int i=row,j=col; i>=0 && j>=0; i--, j--) {
                if(ans[i][j]) return false;
            }
            //dir3
            for(int i=row,j=col; i<n && j>=0; i++, j--) {
                if(ans[i][j]) return false;
            }
            return true;
        }

        void solve(vector<vector<int>>& res, vector<vector<int>>& ans, int col, int n) {
            if(col == n) {
                res = ans;
                return;
            }
            for(int i=0; i<n; i++) {
                if(safe(ans, i, col, n)) {
                    ans[i][col] = 1;
                    solve(res, ans, col+1, n);
                    ans[i][col] = 0;
                }
            }
        }

        vector<vector<int>> nQueen(int n) {
            vector<vector<int>> ans (n, vector<int> (n, 0));
            vector<vector<int>> res;
            solve(res, ans, 0, n);
            return res;
        }

        void print(vector<vector<int>> v) {
            for(vector<int> vi: v) {
                for(int j: vi) {
                    cout<<j<<" ";
                }
                cout<<endl;
            }
        }
};

int main() {
    Sol s;
    int n;
    cin>>n;
    vector<vector<int>> ans = s.nQueen(n);
    s.print(ans);
    return 0;
}
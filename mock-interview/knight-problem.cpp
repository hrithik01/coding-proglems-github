// Knight problem A*B chessboard size and knight at C*D position, find the minimum number of moves to reach E*F position.
#include <iostream>
#include <vector>

using namespace std;

// time and space complexity is O(A*B)
int Solution(int A, int B, int C, int D, int E, int F) {
    vector<vector<int>> dp(A, vector<int>(B, -1));
    vector<vector<int>> dir = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};
    dp[C-1][D-1] = 0;
    for(int i=0; i<A; i++) {
        for(int j=0; j<B; j++) {
            if(dp[i][j] == -1) {
                continue;
            }
            for(int k=0; k<8; k++) {
                int x = i + dir[k][0];
                int y = j + dir[k][1];
                if(x>=0 && x<A && y>=0 && y<B && dp[x][y] == -1) {
                    dp[x][y] = dp[i][j] + 1;
                }
            }
        }
    }
    return dp[E-1][F-1];
}

// time complexity is O(A*B) but avoids unnecessary iterations of moving to all points
int optimised(int A, int B, int C, int D, int E, int F) {
    vector<vector<int>> dp(A, vector<int>(B, -1));
    vector<vector<int>> dir = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};
    dp[C-1][D-1] = 0;
    vector<pair<int, int>> q;
    q.push_back({C-1, D-1});
    for(int i=0; i<q.size(); i++) {
        int x = q[i].first;
        int y = q[i].second;
        for(int k=0; k<8; k++) {
            int x1 = x + dir[k][0];
            int y1 = y + dir[k][1];
            if(x1>=0 && x1<A && y1>=0 && y1<B && dp[x1][y1] == -1) {
                dp[x1][y1] = dp[x][y] + 1;
                q.push_back({x1, y1});
            }
        }
    }
    return dp[E-1][F-1];
}

int main () {
    int A = 8, B = 8, C = 1, D = 1, E = 8, F = 8;
    cout<<"Minimum number of moves to reach from ("<<C<<", "<<D<<") to ("<<E<<", "<<F<<") is -: "<<Solution(A, B, C, D, E, F)<<endl;
    return 0;
}
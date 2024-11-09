#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    int freshOranges = 0, nr=grid.size(), nc=grid[0].size();
    queue<pair<int,int>> q;
    for(int i=0; i<nr; i++) {
        for(int j=0; j<nc; j++) {
            if(grid[i][j] == 1) freshOranges++;
            else if(grid[i][j] == 2) q.push({i,j});
        }
    }
    vector<pair<int,int>> dirs = {{-1,0},{0,-1},{1,0},{0,1}};
    int ans = 0;
    while(!q.empty() && freshOranges>0) {
        int size=q.size();
        for(int i=0; i<size; i++) {
            auto p = q.front();
            q.pop();
            int pi = p.first, pj = p.second;
            for(auto pdir: dirs) {
                int ni = pi + pdir.first;
                int nj = pj + pdir.second;
                if(ni>=0 && nj>=0 && ni<nr && nj<nc && grid[ni][nj]==1) {
                    grid[ni][nj] = 2;
                    q.push({ni,nj});
                    freshOranges--;
                }
            }
        }
        ans++;
    }
    return freshOranges<=0 ? ans : -1;
}

int main() {
    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
        };
    cout << minTimeToRot(grid, 3, 3) << endl;
    return 0;
}
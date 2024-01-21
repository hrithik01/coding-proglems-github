#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<unordered_set<int> > adjList(vector<pair<int, int> > matrix) {
    int n = 0;
    for (pair<int, int> p : matrix) {
        n = max(n, max(p.first, p.second));
    }
    vector<unordered_set<int> > ans(n + 1);
    for (pair<int, int> p : matrix) {
        ans[p.first].insert(p.second);
        ans[p.second].insert(p.first);
    }
    return ans;
}

int main() {
    vector<pair<int, int> > matrix;
    matrix.push_back(make_pair(0, 1));
    matrix.push_back(make_pair(0, 4));
    matrix.push_back(make_pair(0, 5));
    matrix.push_back(make_pair(1, 3));
    matrix.push_back(make_pair(1, 4));
    matrix.push_back(make_pair(2, 1));
    matrix.push_back(make_pair(3, 2));
    matrix.push_back(make_pair(3, 4));

    vector<unordered_set<int> > ans = adjList(matrix);
    for(int i = 0; i < ans.size(); i++) {
        cout << i << ": ";
        for(int j: ans[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
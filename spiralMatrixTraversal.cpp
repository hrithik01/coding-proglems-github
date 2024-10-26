#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralMatrixTraversal (vector< vector<int> > matrix) {
    vector<int> ans;
    int rows = matrix.size(), cols = matrix[0].size(), increasingDir = 1, current_row = 0, current_col = -1;
    while (rows >0 && cols > 0) {
        for(int i=0; i<cols; i++) {
            current_col += increasingDir;
            ans.push_back(matrix[current_row][current_col]);
        }
        rows--;
        for(int i=0; i<rows; i++) {
            current_row += increasingDir;
            ans.push_back(matrix[current_row][current_col]);
        }
        cols--;
        increasingDir *= -1;
    }
    return ans;
}

vector<int> spiralPathMatrix(vector<vector<int>> arr, int n, int m) 
{
    int t=0, b=n-1, l=0, r=m-1;
    vector<int> ans;
    while(t<=b && l<=r) {
        for(int i=l; i<=r; i++) 
            ans.push_back(arr[t][i]);
        t++;
        for(int i=t; i<=b; i++) 
            ans.push_back(arr[i][r]);
        r--;
        if(t<=b) {
            for(int i=r; i>=l; i--)
                ans.push_back(arr[b][i]);
            b--;
        }
        if(l<=r) {
            for(int i=b; i>=t; i--)
                ans.push_back(arr[i][l]);
            l++;
        }
    }
    return ans;
}

int main() {
    vector<vector<int> > matrix = {
        {1, 2, 3, 4, 5},
        {14, 15, 16, 17, 6},
        {13, 20, 19, 18, 7},
        {12, 11, 10, 9, 8}
    };
    vector<int> ans = spiralMatrixTraversal(matrix);
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
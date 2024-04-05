#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

void setZeros(vector<vector<int>> &matrix)
{
	int n = matrix.size();
	int m = matrix[0].size();
	vector<bool> rows(n, 1);
	vector<bool> cols(m, 1);
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(matrix[i][j]==0) {
				rows[i] = 0;
				cols[j] = 0;
			}
		}
	}
	for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(rows[i]==0 || cols[j]==0) matrix[i][j] = 0;
        }
    }
}

int main () {
    cout<<"Hello From Hrithik \n";
    vector<vector<int>> matrix = {{1,1,1},{1,0,0},{1,1,1}};
    setZeros(matrix);
    for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[0].size(); j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
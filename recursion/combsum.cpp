#include <iostream>
#include <vector>

using namespace std;

void fn(vector<int> &ARR, vector<vector<int>>& v, vector<int>& temp, int i, int B, int N, int sum) {
    if(sum == B) {
        v.push_back(temp);
        return;
    }
    if(sum > B) return;
    if(i>=N) return;
    temp.push_back(ARR[i]);
    fn(ARR, v, temp, i, B, N, sum + ARR[i]);
    temp.pop_back();
    fn(ARR, v, temp, i+1, B, N, sum);
}

vector<vector<int>> combSum(vector<int> &ARR, int B)
{
    vector<vector<int>> v;
    vector<int> temp;
    sort(ARR.begin(), ARR.end());
    fn(ARR, v, temp, 0, B, ARR.size(), 0);
    return v;
}



//AVOID DUPLICATE ELEMENTS
void fn2(vector<vector<int>>& v, vector<int>& temp, vector<int> &arr, int n, int B, int i, int sum) {
    if(sum == B) {
        v.push_back(temp);
        return;
    }
    if(sum > B || i >= n) return;

    // Skip duplicates
    for(int j = i; j < n; ++j) {
        if(j > i && arr[j] == arr[j - 1]) continue; // Skip duplicates
        temp.push_back(arr[j]);
        fn2(v, temp, arr, n, B, j + 1, sum + arr[j]);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int B) {
    vector<vector<int>> v;
    vector<int> temp;
    sort(arr.begin(), arr.end());
    fn2(v, temp, arr, arr.size(), B, 0, 0);
    return v;
}

int main() {
    vector<int> ARR = {13, 3, 2, 17};
    int B = 14;
    vector<vector<int>> v = combSum(ARR, B);
    for(auto x: v) {
        for(auto y: x) {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}
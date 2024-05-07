#include <iostream>
#include <vector>

using namespace std;

void generateSubsets(vector<vector<int>>& res, vector<int>& curr, vector<int>& nums, int start) {
    res.push_back(curr);
    for(int i = start; i<nums.size(); i++) {
        curr.push_back(nums[i]);
        generateSubsets(res, curr, nums, i+1);
        curr.pop_back();
    }
}

void print2Dvector(vector<vector<int>>& result) {
    for (auto v : result) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main () {
    vector<int> v = {6,7,8};
    vector<vector<int>> result;
    vector<int> current;
    generateSubsets(result, current, v, 0);
    print2Dvector(result);
    return 0;
}
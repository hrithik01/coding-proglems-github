// Given an array of strings, and another input string S, 
// we have to find all strings which are prefix or suffix of S

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isPrefix(string i, string s) {
    if (i.size() > s.size()) return false;
    for (int j = 0; j < i.size(); j++) {
        if (i[j] != s[j]) return false;
    }
    return true;
}

bool isSuffix(string i, string s) {
    if (i.size() > s.size()) return false;
    for (int j = 0; j < i.size(); j++) {
        if (i[j] != s[s.size() - i.size() + j]) return false;
    }
    return true;
}

// O(n*m)
// O(n*m) - where n is the number of strings and m is the length of the longest string
// O(1) - space complexity
string longestCommonPrefixOptimised(vector<string> vec) {
    if (vec.empty()) return "";
    string prefix = vec[0];
    int n = vec.size();
    int m = prefix.size();
    for (int i = 0; i < m; ++i) {
        char c = prefix[i];
        for (int j = 1; j < n; ++j) {
            if (i == vec[j].size() || vec[j][i] != c)
                return prefix.substr(0, i);
        }
    }
    return prefix;
}

// O(n*m)
// O(1) - space complexity
string longestCommonPrefix(vector<string>& vec) {
    if (vec.empty()) return "";
    string ans = vec[0];
    for(int i=1; i<vec.size(); i++) {
        int j = min(ans.size(), vec[i].size());
        ans = ans.substr(0, j);
        while(j>0 && vec[i].substr(0,j) != ans.substr(0, j)) {
            j--;
        }
        ans = ans.substr(0, j);
        if(j==0) return "";
    }
    return ans;
}

int main() {
    vector<string> arr = {"abab", "aba", "abc", "aaa", "abaa", "abba", "baaa", "bbaa"};
    string s = "abaabbabbaa";
    vector<string> res;
    for (int i = 0; i < arr.size(); i++) {
        if (isPrefix(arr[i], s) || isSuffix(arr[i], s)) {
            res.push_back(arr[i]);
        }
    }
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}
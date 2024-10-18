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
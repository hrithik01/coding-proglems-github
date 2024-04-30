/*
Given two strings, a and b, return an array of all the start indexes of anagrams of b in a. We may return the answer in any order.
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main () {
    string a = "cbaebabacd";
    string b = "abc";
    unordered_map<char, int> m;
    for(char c: b) {
        m[c]++;
    }
    int n = a.size();
    int k = b.size();
    int i = 0;
    int j = 0;
    vector<int> ans;
    while(j < n) {
        if(m.find(a[j]) != m.end()) {
            m[a[j]]--;
            if(m[a[j]] == 0) {
                m.erase(a[j]);
            }
            if(m.empty()) {
                ans.push_back(i);
            }
            j++;
        } else {
            if(m.find(a[i]) != m.end()) {
                m[a[i]]++;
            } else {
                m[a[i]] = 1;
            }
            i++;
        }
    }
    for(int i: ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
/*
Given two strings, a and b, return an array of all the start indexes of anagrams of b in a. We may return the answer in any order.
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.
Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/
class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string, vector<string>> mp;
            vector<vector<string>> ans;
            for(string& s: strs) {
                string sorted = s;
                sort(sorted.begin(), sorted.end());
                mp[sorted].push_back(move(s));
            }
            for(auto& [key, arr]: mp) {
                ans.push_back(move(arr));
            }
            return ans;
        }
    };

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
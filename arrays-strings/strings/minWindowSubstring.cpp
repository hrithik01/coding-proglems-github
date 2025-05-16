/*
Given two strings s and t of lengths m and n respectively, 
return the minimum window substring of s such that every character in t (including duplicates) is included in the window.
 If there is no such substring, return the empty string "".
Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
*/
#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int ns = s.size(), tn = t.size();
        // If target is longer than source, no valid window exists
        if (tn > ns) return "";

        // Frequency tables for characters in t (tvec) and current window in s (svec)
        int tvec[128] = {0}, svec[128] = {0};

        // Build frequency table for t
        for (char c : t)
            tvec[c]++;

        // Count how many unique characters in t must be matched
        int req = 0;
        for (int count : tvec) {
            if (count > 0)
                req++;
        }

        int l = 0, r = 0;
        int curr = 0;               // Number of unique characters currently meeting required frequency
        int ansl = ns + 1, start = 0; // Length and start index of the minimum window found

        // Expand the window by moving r
        while (r < ns) {
            char cr = s[r];
            svec[cr]++;
            // If current character completes its required count, increment curr
            if (tvec[cr] > 0 && svec[cr] == tvec[cr])
                curr++;

            // When all required characters are matched, try contracting from l
            while (l <= r && curr == req) {
                // Update answer if this window is smaller
                if (r - l + 1 < ansl) {
                    ansl = r - l + 1;
                    start = l;
                }
                char cl = s[l];
                // Remove the leftmost character from the window
                svec[cl]--;
                // If removal causes a deficit in a required character, decrement curr
                if (tvec[cl] > 0 && svec[cl] < tvec[cl])
                    curr--;
                l++;
            }

            r++;
        }

        // Return the minimum window substring or empty string if none found
        return ansl == ns + 1 ? "" : s.substr(start, ansl);
    }
};

// Time Complexity: O(n), where n is the length of s
// Space Complexity: O(1), since the size of the hash table is constant (128 characters)

// The above code uses a sliding window approach to find the minimum window substring.
// It maintains a count of characters in the current window and compares it with the required count from string t.
// The outer loop expands the window by moving the right pointer, while the inner loop shrinks the window by moving the left pointer.
// The algorithm keeps track of the minimum length of the valid window found so far and returns the corresponding substring.

int main() {
    Solution sol;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << sol.minWindow(s, t) << endl; // Output: "BANC"
    return 0;
}
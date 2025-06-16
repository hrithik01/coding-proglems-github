/*
1) Longest Common Substring
2) Longest Common Subsequence
3) Longest Palindromic Substring
4) Longest Palindromic Subsequence
5) Longest Repeating Substring
6) Longest Repeating Subsequence
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Problem Approach Summary:
// We employ a dynamic programming solution with a rolling array to save space.
// For each position (i, j), we compute the length of the longest common suffix ending at those indices.
// Time Complexity: O(m * n)
// Space Complexity: O(n)
string longestCommonSubstring(string& s1, string& s2) {
    int m = s1.size(), n = s2.size(), len = 0, endIdx = 0;
    // prevdp[j] stores length of longest common suffix ending at s1[i-1], s2[j-1] for previous i
    vector<int> prevdp(n + 1, 0);
    for (int i = 1; i <= m; i++) {
        // currdp[j] will store length of longest common suffix ending at s1[i-1], s2[j-1] for current i
        vector<int> currdp(n + 1, 0);
        for (int j = 1; j <= n; j++) {
            // If characters match, extend the previous suffix length by 1
            if (s1[i - 1] == s2[j - 1]) {
                currdp[j] = prevdp[j - 1] + 1;

                // Update max length and record ending index in s1
                if (currdp[j] > len) {
                    len = currdp[j];
                    endIdx = i;
                }
            }
            // If they don't match, currdp[j] remains 0 (no common suffix here)
        }
        // Slide the window: current row becomes previous for next iteration
        prevdp = move(currdp);
    }
    // Extract and return the longest common substring from s1
    return s1.substr(endIdx - len, len);
}


string longestPalindromicSubstring(string& s) {
    int n = s.size(), l = 0, r = 0, ans = 1, sidx = 0;
    if(n == 0) return s;
    for(int i=0; i<n; i++) {
        for(int j=0; j<=1; j++) {
            l = i; r = i+j;
            while(l>=0 && r<n && s[l] == s[r]) {
                if(r-l+1 > ans) {
                    sidx = l;
                    ans = r-l+1;
                }
                l--;
                r++;
            }
        }
    }
    return s.substr(sidx, ans);
}

int main () {
    // string s1 = "abcdefg";
    // string s2 = "xyzabcde";
    // string result = longestCommonSubstring(s1, s2);
    // cout << "Longest Common Substring: " << result << endl;

    string si = "geeks", sj = "a", sk = "qaacccaag";
    cout<<"LPSubstring "<<longestPalindromicSubstring(si)<<endl<<longestPalindromicSubstring(sj)<<endl<<longestPalindromicSubstring(sk)<<endl;
    return 0;
}
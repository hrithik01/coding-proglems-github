/*
You are given an absolute path for a Unix-style file system, which always begins with a slash '/'. 
Your task is to transform this absolute path into its simplified canonical path.
The rules of a Unix-style file system are as follows:

A single period '.' represents the current directory.
A double period '..' represents the previous/parent directory.
Multiple consecutive slashes such as '//' and '///' are treated as a single slash '/'.
Any sequence of periods that does not match the rules above should be treated as a valid directory or file name. For example, '...' and '....' are valid directory or file names.
The simplified canonical path should follow these rules:

The path must start with a single slash '/'.
Directories within the path must be separated by exactly one slash '/'.
The path must not end with a slash '/', unless it is the root directory.
The path must not have any single or double periods ('.' and '..') used to denote current or parent directories.
Return the simplified canonical path.

Example 1:
Input: path = "/home/"
Output: "/home"
Explanation:
The trailing slash should be removed.

Example 2:
Input: path = "/home//foo/"
Output: "/home/foo"
Explanation:
Multiple consecutive slashes are replaced by a single one.
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;
// Worst-case Time Complexity: O(n)
// Worst-case Space Complexity: O(n)
class Solution {
public:
    string simplifyPath(string s) {
        // Stack to keep track of valid path segments
        stack<string> stk;
        string token = "";
        int n = s.size();
        // Iterate through the string, splitting segments on '/'
        for (int i = 0; i <= n; i++) {
            if (i == n || s[i] == '/') {
                // Handle parent directory reference ".."
                if (token == "..") {
                    if (!stk.empty()) stk.pop();
                }
                // Handle valid directory names (ignore "." and empty tokens)
                else if (!token.empty() && token != ".") {
                    stk.push(token);
                }
                // Reset token for next segment
                token = "";
            }
            else {
                // Build the current segment character by character
                token += s[i];
            }
        }
        // If no valid segments remain, return root "/"
        if (stk.empty()) {
            return "/";
        }
        // Reconstruct the simplified canonical path
        string result = "";
        while (!stk.empty()) {
            result = "/" + stk.top() + result;
            stk.pop();
        }
        return result;
    }
};

// Overall Approach Summary:
// - Use a stack to process path segments in one pass.
// - Push valid directory names, pop on "..", ignore "." and empty segments.
// - Reconstruct the canonical path by popping from the stack.
// Time Complexity: O(n), Space Complexity: O(n)

int main() {
    Solution sol;
    string path = "/a/./b/../../c/";
    cout << sol.simplifyPath(path) << endl; // Output: "/c"
    return 0;
}   
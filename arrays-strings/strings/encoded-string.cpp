/*
Sample Input 1: 
3[a]2[bc] a1[b]1[cc] ab2[c3[b]] 
Sample Output 1: 
aaabcbc abcc abcbbbcbbb
*/

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

int char2int(char c) {
    return c - '0';
}

string decodeString(string s) {
    stack<char> stk;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ']') {
            string tempStr = "";
            while (!stk.empty() && stk.top() != '[') {
                // PREPENDING CHARACTERS IS MOST IMPORTANT TO AVOID REVERSING
                tempStr = stk.top() + tempStr;
                stk.pop();
            }
            stk.pop(); // pop '['

            string numStr = "";
            while (!stk.empty() && is_digit(stk.top())) {
                //PRPENDING HERE ALSO
                numStr = stk.top() + numStr;
                stk.pop();
            }
            int tempDigit = stoi(numStr);

            string expandedStr = "";
            for (int j = 0; j < tempDigit; j++) {
                expandedStr += tempStr;
            }

            for (char c : expandedStr) {
                stk.push(c);
            }
        } else {
            stk.push(s[i]);
        }
    }

    string ans = "";
    while (!stk.empty()) {
        // PREPENDING
        ans = stk.top() + ans;
        stk.pop();
    }

    return ans;
}

int main() {
    vector<string> inputs = {"2[l4[gymmj]]", "a1[b]1[cc]", "ab2[c3[b]]"};
    for (const string& input : inputs) {
        cout << decodeString(input) << endl;
    }
    return 0;
}
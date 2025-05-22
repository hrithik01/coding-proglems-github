/*
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
Evaluate the expression. Return an integer that represents the value of the expression.
Note that:
The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
Example 1:
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& arr) {
        stack<int> stk;
        unordered_map<string, function<int(int,int)>> ops = {
            {"+", [](int a, int b) { return a + b; }},
            {"-", [](int a, int b) { return a - b; }},
            {"*", [](int a, int b) { return a * b; }},
            {"/", [](int a, int b) { return a / b; }}
        };
        for(int i=0; i<arr.size(); i++) {
            string s = arr[i];
            if(s=="+" || s=="-" || s=="*" || s=="/") {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                stk.push(ops[s](a,b));
            } else {
                stk.push(stoi(arr[i]));
            }
        }
        return stk.top();
    }

    int evalRPNFn2(vector<string>& tokens) {
        stack<int> numStack;
        for (int idx = 0; idx < tokens.size(); idx++) {
            if (tokens[idx].size() != 1) {
                numStack.push(stoi(tokens[idx]));
                continue;
            }
            switch (tokens[idx][0]) {
                case '+':
                case '-':
                case '*':
                case '/':
                    calcNewNumFn2(numStack, tokens[idx][0]);
                    break;
                default:
                    numStack.push(stoi(tokens[idx]));
            }
        }
        return numStack.top();
    }

    void calcNewNumFn2(stack<int>& numStack, char oper) {
        int num1 = numStack.top();
        numStack.pop();
        int num2 = numStack.top();
        numStack.pop();
        int newNum = 0;
        switch (oper) {
            case '+':
                newNum = num2 + num1;
                break;
            case '-':
                newNum = num2 - num1;
                break;
            case '*':
                newNum = num2 * num1;
                break;
            default:
                newNum = num2 / num1;
        }
        numStack.push(newNum);
    }
};

int main() {
    Solution sol;
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout << "Result: " << sol.evalRPN(tokens) << endl; // Output: 9
    tokens = {"4", "13", "5", "/", "+"};
    cout << "Result: " << sol.evalRPN(tokens) << endl; // Output: 6
}
/*
Given a string s representing a valid expression, 
implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, 
such as eval().
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> dig;    // stack for operands (numbers)
        stack<char> ops;   // stack for operators and parentheses
        int i = 0, n = s.size();

        // Lambda to apply the top operator on top two operands
        // Capture by reference [&] so we can modify dig and ops directly
        auto applyOp = [&]() {
            // Pop top two numbers
            int b = dig.top(); 
            dig.pop();
            int a = dig.top(); 
            dig.pop();
            // Pop the operator
            char op = ops.top(); 
            ops.pop();
            // Perform operation and push result back
            // '+' for add, '-' for subtract
            dig.push(op == '+' ? a + b : a - b);
        };

        // Iterate through the string
        while (i < n) {
            char c = s[i];
            if (c == ' ') {
                // Skip spaces
                i++;
            } else if (isdigit(c)) {
                // Parse a full multi-digit number
                int temp = 0;
                while (i < n && isdigit(s[i])) {
                    temp = temp * 10 + (s[i] - '0');
                    i++;
                }
                dig.push(temp);
            } else if (c == '(') {
                // Push '(' to ops stack
                ops.push(c);
                i++;
            } else if (c == '+' || c == '-') {
                // Detect unary operator: if at start or after '(' (skip spaces)
                int j = i - 1;
                while (j >= 0 && s[j] == ' ') j--;
                if (j < 0 || s[j] == '(') {
                    // Treat unary +/− as 0 + x or 0 - x
                    dig.push(0);
                }
                // Apply any pending + or - before pushing current operator
                while (!ops.empty() && ops.top() != '(') {
                    applyOp();
                }
                ops.push(c);
                i++;
            } else if (c == ')') {
                // Compute until matching '('
                while (!ops.empty() && ops.top() != '(') {
                    applyOp();
                }
                // Pop the '('
                ops.pop();
                i++;
            } else {
                // Any other character (shouldn't occur in valid input)
                i++;
            }
        }

        // Apply remaining operators
        while (!ops.empty()) {
            applyOp();
        }

        // Final result is on top of dig stack
        return dig.empty() ? 0 : dig.top();
    }

    int calculate2(string s) {
        int sign = 1;
        stack<int> st;
        int result = 0;
        int operand = 0;
        for (int c : s) {
            if (isdigit(c)) {
                // Build the current operand
                operand = operand * 10 + (c - '0');
                continue;
            }

            if (c == '+') {
                // Add the previous operand
                result += sign * operand;
                sign = 1;
                operand = 0;
            }

            if (c == '-') {
                // Subtract the previous operand
                result += sign * operand;
                sign = -1;
                operand = 0;
            }

            if (c == '(') {
                // Push current result and sign for later
                st.push(result);
                st.push(sign);
                // Reset for new sub-expression
                sign = 1;
                result = 0;
                operand = 0;
            }

            if (c == ')') {
                // Complete current sub-expression
                result += operand * sign;
                // Apply the sign before '('
                result *= st.top(); 
                st.pop();
                // Add the result before '('
                result += st.top();
                st.pop();
                operand = 0;
            }
        }

        // Add any remaining operand
        return result + operand * sign;
    }
};

int main () {
    Solution s;
    string str = "1 + 1";
    cout << s.calculate(str) << endl; // 2
    str = " 2-1 + 2 ";
    cout << s.calculate(str) << endl; // 3
    str = "(1+(4+5+2)-3)+(6+8)";
    cout << s.calculate(str) << endl; // 23
    return 0;
}

/*
Overall Approach Summary:
- Use two stacks: one for operands (numbers) and one for operators/parentheses.
- Parse the string character by character:
  * Skip spaces.
  * Read multi-digit numbers and push onto operand stack.
  * Push '(' onto operator stack.
  * For '+' or '-', handle unary cases by pushing a 0 operand, then apply higher-precedence ops.
  * For ')', apply operators until matching '('.
- After parsing, apply any remaining operators.
- The final result is the top of the operand stack.

Time Complexity: O(n), where n is the length of the string (each character is processed a constant number of times).
Space Complexity: O(n), for the two stacks storing operators and operands.
*/
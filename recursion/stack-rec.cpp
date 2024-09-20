#include <iostream>
#include <stack>

using namespace std;

void pushReverse(stack<int>& stk, int k) {
    if(stk.empty()) {
        stk.push(k);
        return;
    }
    int t = stk.top();
    stk.pop();
    pushReverse(stk, k);
    stk.push(t);
}

void reverseStk(stack<int>& stk) {
    if(stk.empty()) return;
    int k = stk.top();
    stk.pop();
    reverseStk(stk);
    pushReverse(stk, k);
}

void pushSort(stack<int>& stk, int k) {
    if(stk.empty() || k >= stk.top()) {
        stk.push(k);
        return;
    }
    int t = stk.top();
    stk.pop();
    pushSort(stk, k);
    stk.push(t);
}

void sortStk(stack<int>& stk) {
    if(stk.empty()) return;
    int k = stk.top();
    stk.pop();
    sortStk(stk);
    pushSort(stk, k);
}

void printStk(stack<int> stk) {
    while(!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

int main() {
    stack<int> stk;
    stk.push(1);
    stk.push(3);
    stk.push(2);
    stk.push(5);
    stk.push(4);

    sortStk(stk);
    printStk(stk);

    reverseStk(stk);
    printStk(stk);
    return 0;
}
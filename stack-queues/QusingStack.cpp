#include <iostream>
#include <vector>

class Stack {
private:
    std::vector<int> stackList;

public:
    bool isEmpty() {
        return stackList.empty();
    }

    int top() {
        if (isEmpty()) {
            return -1; // Assuming -1 indicates an empty stack
        }
        return stackList.back();
    }

    int size() {
        return stackList.size();
    }

    void push(int value) {
        stackList.push_back(value);
    }

    int pop() {
        if (isEmpty()) {
            return -1; // Assuming -1 indicates an empty stack
        }
        int top_value = stackList.back();
        stackList.pop_back();
        return top_value;
    }
};

class MyQueueUsingStack {

public:
    Stack s1, s2;
    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if(!s2.isEmpty()) {
            return s2.pop();
        }
        while(!s1.isEmpty())
            s2.push(s1.pop());
        return s2.pop();
    }

    int peek() {
        if(!s2.isEmpty())
            return s2.top();
        
        while(!s1.isEmpty())
            s2.push(s1.pop());
        return s2.top();
    }

    bool empty() {
        if(!s1.isEmpty() || !s2.isEmpty())
            return false;
        return true;
    }
};

int main () {
    MyQueueUsingStack q;
    q.push(1);
    q.push(2);
    q.push(3);
    std::cout << q.peek() << std::endl;
    q.pop();
    std::cout << q.peek() << std::endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int push(queue<int>& q1, queue<int>& q2, int x) {
    q1.push(x);
    cout<<"Pushed "<<x<<" in the stack\n";
    return x;
}

int pop(queue<int>& q1, queue<int>& q2) {
    if(q1.empty()) {
        cout<<"Stack is empty\n";
        return 0;
    }
    while(q1.size() != 1) {
        q2.push(q1.front());
        q1.pop();
    } 
    int x = q1.front();
    q1.pop();
    queue<int> q = q1;
    q1 = q2;
    q2 = q;
    cout<<"Popped "<<x<<" from the stack\n";
    return x;
}

int top(queue<int>& q1, queue<int>& q2) {
    if(q1.empty()) {
        cout<<"Stack is empty\n";
        return 0;
    }
    while(q1.size() != 1) {
        q2.push(q1.front());
        q1.pop();
    } 
    int x = q1.front();
    q2.push(q1.front());
    q1.pop();
    queue<int> q = q1;
    q1 = q2;
    q2 = q;
    cout<<"Top element is "<<x<<endl;
    return x;
}

int isEmpty(queue<int>& q1, queue<int>& q2) {
    if(q1.empty()) {
        cout<<"Stack is empty\n";
        return 1;
    }
    cout<<"Stack is not empty\n";
    return 0;
}

int size(queue<int>& q1, queue<int>& q2) {
    cout<<"Size of the stack is "<<q1.size()<<endl;
    return q1.size();
}

void printStack(queue<int>& q1, queue<int>& q2) {
    queue<int> q = q1;
    vector<int> temp;
    while(!q.empty()) {
        temp.push_back(q.front());
        q.pop();
    }
    for(int i = temp.size() - 1; i >= 0; i--) {
        cout << temp[i] << " ";
    }
    cout << endl;
}

class SUQ {
    private:
        queue<int> q;
    public:
        void push(int x) {
            int sizeq = q.size();
            q.push(x);
            while(sizeq--) {
                q.push(q.front());
                q.pop();
            }
        }
        int pop() {
            int n = q.front();
            q.pop();
            return n;
        }
        int top() {
            return q.front();
        }
        bool empty() {
            return q.empty();
        }
};

int main () {
//     queue<int> q1, q2;
//    cout<<"push -: "<<push(q1, q2, 1)<<endl;
//    cout<<"push -: "<<push(q1, q2, 2)<<endl;
//    cout<<"push -: "<<push(q1, q2, 3)<<endl;
//     cout<<"push -: "<<push(q1, q2, 4)<<endl;
//     cout<<"push -: "<<push(q1, q2, 5)<<endl;
//     cout<<"print Stack \n";
//     printStack(q1, q2);
//     cout<<"pop -: \n"<<endl;
//     pop(q1, q2);
//     cout<<"print -: \n"<<endl;
//     printStack(q1, q2);
//     cout<<"top -: \n"<<endl;
//     top(q1, q2);
//     cout<<"print -: \n"<<endl;
//     printStack(q1, q2);
//     cout<<"isEmpty -: \n"<<endl;
//     isEmpty(q1, q2);
//     cout<<"size -: \n"<<endl;
//     size(q1, q2);
//     cout<<"pop -: \n"<<endl;
//     pop(q1, q2);
//     cout<<"pop -: \n"<<endl;
//     pop(q1, q2);
//     cout<<"top -: \n"<<endl;
//     top(q1, q2);
//     cout<<"print -: \n"<<endl;
//     printStack(q1, q2);
    SUQ s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<"Top element is -: "<<s.top()<<endl;
    cout<<"Popped element is -: "<<s.pop()<<endl;
    cout<<"Top element is -: "<<s.top()<<endl;
    cout<<"Popped element is -: "<<s.pop()<<endl;
    cout<<"Top element is -: "<<s.top()<<endl;
    cout<<"Popped element is -: "<<s.pop()<<endl;
    cout<<"Is stack empty -: "<<s.empty()<<endl;
    return 0;
}
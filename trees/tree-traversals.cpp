#include <vector>
#include <iostream>
#include <stack>

using namespace std;

/*
            1
        2       3
      4   5   6   7
*/

struct tnode {
    int val;
    tnode* left;
    tnode* right;
    tnode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void recPRE(vector<int>& ans, tnode* root) {
    // Root -> Left -> Right
    if(!root) return;
    ans.push_back(root->val);
    recPRE(ans, root->left);
    recPRE(ans, root->right);
}
void iterPRE(vector<int>& ans, tnode* root) {
    stack<tnode*> s;
    s.push(root);
    while(!s.empty()) {
        tnode* temp = s.top();
        s.pop();
        ans.push_back(temp->val);

        if(temp->right) s.push(temp->right);
        if(temp->left) s.push(temp->left);
    }
}

void recIN(vector<int>& ans, tnode* root) {
    // Left -> Root -> Right
    if(!root) return;
    recIN(ans, root->left);
    ans.push_back(root->val);
    recIN(ans, root->right);
}
void iterIN(vector<int>& ans, tnode* root) {
    stack<tnode*> s;
    tnode* temp = root;
    while(true) {
        if(temp) {
            s.push(temp);
            temp = temp->left;
        } else {
            if(s.empty()) return;
            temp = s.top();
            s.pop();
            ans.push_back(temp->val);
            temp = temp->right;
        }
    }
}

void recPOST(vector<int>& ans, tnode* root) {
    // Left -> Right -> Root
    if(!root) return;
    recPOST(ans, root->left);
    recPOST(ans, root->right);
    ans.push_back(root->val);
}
void iterPOST(vector<int>& ans, tnode* root) {
    stack<tnode*> s;
    tnode* temp = root;
    s.push(temp);
    while(!s.empty()) {
        temp = s.top();
        s.pop();
        ans.push_back(temp->val);
        if(temp->left) s.push(temp->left);
        if(temp->right) s.push(temp->right);
    }
    reverse(ans.begin(), ans.end());
}

void printVecNclear(vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    v.clear();
}

int main() {
    tnode* root = new tnode(1);
    root->left = new tnode(2);
    root->right = new tnode(3);
    root->left->left = new tnode(4);
    root->left->right = new tnode(5);
    root->right->left = new tnode(6);
    root->right->right = new tnode(7);

    vector<int> ans;

    // Preorder
    recPRE(ans, root);
    printVecNclear(ans);

    // Inorder
    recIN(ans, root);
    printVecNclear(ans);

    // Postorder
    recPOST(ans, root);
    printVecNclear(ans);

    cout<<endl;

    // Iterative Preorder
    iterPRE(ans, root);
    printVecNclear(ans);

    // Iterative Inorder
    iterIN(ans, root);
    printVecNclear(ans);

    // Iterative Postorder
    iterPOST(ans, root);
    printVecNclear(ans);

    return 0;
}
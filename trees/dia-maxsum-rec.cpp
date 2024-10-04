#include <iostream>

using namespace std;

class tnode {
    public:
        int data;
        tnode* left;
        tnode* right;

        tnode(int data) {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
};

int max_dia(tnode* root, int& ans) {
    if(!root) return 0;
    int lh = max_dia(root->left, ans);
    int rh = max_dia(root->right, ans);
    ans = max(ans, lh + rh +1);
    return max(lh, rh) + 1;
}

int max_path_sum(tnode* root, int& ans) {
    if(!root) return 0;
    int lsum = max(0, max_path_sum(root->left, ans));
    int rsum = max(0, max_path_sum(root->right, ans));
    ans = max(ans, lsum + rsum + root->data);
    return max(lsum, rsum) + root->data;
}

int height(tnode* root) {
    if(!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

bool balancedTree(tnode* root) {
    if(!root) return true;
    int lh = height(root->left);
    int rh = height(root->right);
    return abs(lh - rh) <= 1 && balancedTree(root->left) && balancedTree(root->right);
}

int main() {
    tnode* root = new tnode(-5);
    root->left = new tnode(-4);
    root->left->left = new tnode(-3);
    root->left->right = new tnode(-2);
    root->right = new tnode(-6);
    int maxD = 0, maxSum = INT_MIN;
    max_dia(root, maxD);
    max_path_sum(root, maxSum);
    cout<<maxD<<endl;
    cout<<maxSum<<endl;
    cout<<balancedTree(root)<<endl;
    return 0;
}
#include <iostream>
#include <unordered_map>

using namespace std;
template<class T>

class TreeNode {
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(const T data) : data(data), left(nullptr), right(nullptr) {}
};

// DiameterOfBinaryTree returns the diameter of tree
void fillHeightsMap(TreeNode<int> *root, unordered_map<TreeNode<int>*, int> &m) {
    if (root == nullptr) {
        return;
    }
    fillHeightsMap(root->left, m);
    fillHeightsMap(root->right, m);
    int leftHeight = (root->left != nullptr) ? m[root->left] : 0;
    int rightHeight = (root->right != nullptr) ? m[root->right] : 0;
    m[root] = max(leftHeight, rightHeight) + 1;
}


int DiameterOfBinaryTree(TreeNode<int> *root)
{
    unordered_map<TreeNode<int>*, int> m;
    fillHeightsMap(root, m);
    int maxDia = 0;
    for( unordered_map<TreeNode<int>*, int>:: iterator it = m.begin(); it != m.end(); it++) {
        int lh = it->first->left ? m[it->first->left] : 0;
        int rh = it->first->right ? m[it->first->right] : 0;
        maxDia = max(maxDia,  lh + rh);
    }
    return maxDia;
}

int main() {
    TreeNode<int> *root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->left->left = new TreeNode<int>(5);

    int maxDia = 0;
    cout << DiameterOfBinaryTree(root) << endl;
    return 0;
}
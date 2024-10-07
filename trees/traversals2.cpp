#include <vector>
#include <iostream>
#include <queue>
#include <map>

using namespace std;

/*
            1
        2       3
      4   5   6   7
    8   9
*/

struct tnode {
    int val;
    tnode* left;
    tnode* right;
    tnode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//ZIGZAG
void zigzag_traversal(vector<int>& v, tnode* root) {
    bool l2r = true;
    queue<tnode*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        vector<int> temp;
        while(size--)
        {
            tnode* node = q.front();
            q.pop();
            temp.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        if(!l2r) reverse(temp.begin(), temp.end());
        v.insert(v.end(), temp.begin(), temp.end());
        l2r = !l2r;
    }
}

//BOUNDARY
bool is_leaf_node(tnode* root) {
    return !root->left && !root->right;
}

void inorder_boundary_leaf(vector<int>& v, tnode* root) {
    if(!root) return;
    inorder_boundary_leaf(v, root->left);
    if(is_leaf_node(root)) v.push_back(root->val);
    inorder_boundary_leaf(v, root->right);
}

void border_traversal(vector<int>& v, tnode* root) {
    v.push_back(root->val);

    //Left Left
    tnode* curr = root->left;
    while(curr) {
        if(!is_leaf_node(curr)) v.push_back(curr->val);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }

    //Leaf nodes
    inorder_boundary_leaf(v, root);

    //Right Right Reverse
    curr = root->right;
    vector<int> temp;
    while(curr) {
        if(!is_leaf_node(curr)) temp.push_back(curr->val);
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }
    reverse(temp.begin(), temp.end());
    v.insert(v.end(), temp.begin(), temp.end());
}

// VERTICAL
void vertical_traversal(vector<int>& v, tnode* root) {
    map<int, vector<int>> mp;
    queue<pair<int, tnode*>> q;
    q.push({0, root});
    while(!q.empty()) {
        pair<int, tnode*> p = q.front();
        q.pop();
        int p_horizontal_idx = p.first;
        tnode* p_node = p.second;
        mp[p_horizontal_idx].push_back(p_node->val);
        if(p_node->left) q.push({ p_horizontal_idx - 1, p_node->left });
        if(p_node->right) q.push({ p_horizontal_idx + 1, p_node->right });
    }
    for(auto i: mp) {
        vector<int> temp = i.second;
        v.insert(v.end(), temp.begin(), temp.end());
    }
}

void print_clear_vector(vector<int>& v) {
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
    root->left->left->left = new tnode(8);
    root->left->left->right = new tnode(9);

    vector<int> ans;

    zigzag_traversal(ans, root);
    print_clear_vector(ans);

    border_traversal(ans, root);
    print_clear_vector(ans);

    vertical_traversal(ans, root);
    print_clear_vector(ans);

    return 0;
}
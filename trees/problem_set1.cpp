#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <set>

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

void print_clear_vector(vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    v.clear();
}

void top_view(vector<int>& v, tnode* root) {
    map<int, int> mp;
    queue<pair<tnode*, int>> q;
    q.push({root, 0});
    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        int horizontal_idx = p.second;
        tnode* node = p.first;
        if(mp.find(horizontal_idx) == mp.end()) mp[horizontal_idx] = node->val;
        if(node->left) q.push({ node->left, horizontal_idx - 1 });
        if(node->right) q.push({ node->right, horizontal_idx + 1 });
    }
    for(auto i: mp)
        v.push_back(i.second);
    print_clear_vector(v);
}

void bottom_view(vector<int>& v, tnode* root) {
    map<int, int> mp;
    queue<pair<tnode*, int>> q;
    q.push({root, 0});
    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        int horizontal_idx = p.second;
        tnode* node = p.first;
        // Replacing the top element with bottom one for bottom view for same hor_idx
        mp[horizontal_idx] = node->val;
        if(node->left) q.push({ node->left, horizontal_idx - 1 });
        if(node->right) q.push({ node->right, horizontal_idx + 1 });
    }
    for(auto i: mp)
        v.push_back(i.second);
    print_clear_vector(v);
}

void right_view(vector<int>& v, tnode* root) {
    // use level order traversal, instead hor_idx,use ver_idx + 1 like top view
}

tnode* lca(tnode* root, int r1, int r2) {
    if(!root) return nullptr;
    int root_val = root->val;
    if(root_val == r1 || root_val == r2) return root;
    tnode* left = lca(root->left, r1, r2);
    tnode* right = lca(root->right, r1, r2);
    if(left && right) return root;
    return left ? left : right;
}

tnode* lca_3nodes(tnode* root, tnode* r1, tnode* r2, tnode* r3) {
    if(!root || set<tnode*>{r1, r2, r3}.count(root)) return root;
    tnode* l = lca_3nodes(root->left, r1, r2, r3);
    tnode* r = lca_3nodes(root->right, r1, r2, r3);
    if(l && r) return root;
    return l ? l : r;
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
    // top_view(ans, root);
    // bottom_view(ans, root);

    tnode* ans_root = lca_3nodes(root, root->right, root->right->left, root->left->right);
    cout<<ans_root->val<<endl;

    return 0;
}
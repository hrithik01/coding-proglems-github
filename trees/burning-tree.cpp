#include <iostream>
#include <map>
#include <queue>

using namespace std;

struct node {
    int data;
    node *left, *right;
    node(int n): data(n), left(nullptr), right(nullptr) {} 
};

node* target_node_parent_map(node* root, int target, map<node*, node*>& pmap) {
    queue<node*> q;
    q.push(root);
    node* ans;
    pmap[root] = nullptr;
    while(!q.empty()) {
        node* temp = q.front();
        q.pop();
        if(temp->data == target) {
            ans = temp;
        }
        if(temp->left) {
            pmap[temp->left] = temp;
            q.push(temp->left);
        }
        if(temp->right) {
            pmap[temp->right] = temp;
            q.push(temp->right);
        }
    }
    return ans;
}

int burning_tree(node* root, int target) {
    map<node*, node*> pmap;
    node* target_node = target_node_parent_map(root, target, pmap);

    queue<node*> q;
    map<node*, bool> vis;

    q.push(target_node);
    vis[target_node] = true;
    int time = 0;

    while(!q.empty()) {
        int size = q.size();
        bool burnt_in_curr_iteration = false;

        for(int i=0; i<size; i++) {
            node* temp = q.front();
            q.pop();

            if(temp->left && !vis[temp->left]) {
                q.push(temp->left);
                vis[temp->left] = true;
                burnt_in_curr_iteration = true;
            }

            if(temp->right && !vis[temp->right]) {
                q.push(temp->right);
                vis[temp->right] = true;
                burnt_in_curr_iteration = true;
            }

            if(pmap[temp] && !vis[pmap[temp]]) {
                q.push(pmap[temp]);
                vis[pmap[temp]] = true;
                burnt_in_curr_iteration = true;
            }
        }
        if(burnt_in_curr_iteration) time++;
    }
    return time;
}

/*
    1
   / \
  2   3
 /   /  \
4   6    7
*/
int main () {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout << burning_tree(root, 2) << endl;

    return 0;
}
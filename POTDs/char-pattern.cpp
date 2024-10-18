#include <vector>
#include <iostream>
#include <map>

using namespace std;

struct tnode {
    int n;
    tnode* left;
    tnode* right;
    tnode* random;
    tnode(int x) : n(x), left(nullptr), right(nullptr), random(nullptr) {}
};
/* PROBLEM-1
Sample Input 1:
5
Sample Output 1:
E
DE
CDE
BCDE
ABCDE
*/

//PROBLEM-2
vector<vector<char>> interestingPattern(int n)
{
    char initialC = 'A' + n - 1;
    vector<vector<char>> ans;
    vector<char> temp;
    while(n--) {
        temp.insert(temp.begin(), initialC);
        initialC--;
        ans.push_back(temp);
    }
    return ans;
}

tnode* createTree(tnode* root, map<tnode*, tnode*>& mp) {
    if(!root) return nullptr;
    tnode* newRoot = new tnode(root->n);
    mp[root] = newRoot;
    newRoot->left = createTree(root->left, mp);
    newRoot->right = createTree(root->right, mp);
    return newRoot;
}

tnode* cloneBinaryTreeRandomPointer(tnode* root)
{
      map<tnode*, tnode*> mp;
      tnode* newRoot = createTree(root, mp);
        for(auto i: mp) {
            tnode* oldNode = i.first;
            tnode* newNode = i.second;
            newNode->random = mp[oldNode->random];
        }
        return newRoot;
}

void printTree(tnode* root) {
    if(!root) return;
    cout << root->n << " ";
    if(root->random) cout << root->random->n << " ";
    else cout << "X ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    tnode* root = new tnode(1);
    root->left = new tnode(2);
    root->right = new tnode(3);
    root->left->left = new tnode(4);
    root->left->right = new tnode(5);
    root->right->left = new tnode(6);
    root->right->right = new tnode(7);
    root->random = root->left->right;
    root->left->left->random = root->right;
    root->left->right->random = root->right->left;

    tnode* newRoot = cloneBinaryTreeRandomPointer(root);
    printTree(root);
    cout << endl;
    printTree(newRoot);
    cout << endl;

    return 0;
}
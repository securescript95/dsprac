#include <bits/stdc++.h>
using namespace std;
struct Node { int key; Node *left, *right; int height; Node(int k): key(k), left(nullptr), right(nullptr), height(1) {} };
int height(Node* n) { return n ? n->height : 0; }
int balanceFactor(Node* n) { return n ? height(n->left) - height(n->right) : 0; }
void updateHeight(Node* n) { if(n) n->height = 1 + max(height(n->left), height(n->right)); }
Node* rightRotate(Node* y) { Node* x = y->left; Node* T2 = x->right; x->right = y; y->left = T2; updateHeight(y); updateHeight(x); return x; }
Node* leftRotate(Node* x) { Node* y = x->right; Node* T2 = y->left; y->left = x; x->right = T2; updateHeight(x); updateHeight(y); return y; }
Node* insert(Node* node, int key) {
    if(!node) return new Node(key);
    if(key < node->key) node->left = insert(node->left, key);
    else if(key > node->key) node->right = insert(node->right, key);
    else return node;
    updateHeight(node);
    int bf = balanceFactor(node);
    if(bf > 1 && key < node->left->key) return rightRotate(node);
    if(bf < -1 && key > node->right->key) return leftRotate(node);
    if(bf > 1 && key > node->left->key) { node->left = leftRotate(node->left); return rightRotate(node); }
    if(bf < -1 && key < node->right->key) { node->right = rightRotate(node->right); return leftRotate(node); }
    return node;
}
bool search(Node* node, int key) { if(!node) return false; if(node->key == key) return true; if(key < node->key) return search(node->left, key); else return search(node->right, key); }
void inorder(Node* n) { if(!n) return; inorder(n->left); cout << n->key << " "; inorder(n->right); }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Node* root = nullptr;
    cout << "----- AVL TREE DEMO -----\n";
    vector<int> vals = {10, 20, 30, 40, 50, 25};
    for(int v: vals) {
        root = insert(root, v);
        cout << "Inserted " << v << ", Inorder: ";
        inorder(root);
        cout << "\n";
    }
    cout << "Search 25: " << (search(root, 25) ? "Found" : "Not Found") << "\n";
    cout << "Search 100: " << (search(root, 100) ? "Found" : "Not Found") << "\n";
    return 0;
}
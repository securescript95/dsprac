#include <bits/stdc++.h>
using namespace std;
struct Node { int val; Node *l, *r; Node(int v): val(v), l(nullptr), r(nullptr) {} };
class BST {
    Node* root;
    Node* insert(Node* node, int x) { if(!node) return new Node(x); if(x < node->val) node->l = insert(node->l, x); else if(x > node->val) node->r = insert(node->r, x); return node; }
    Node* findMin(Node* node) { while(node->l) node = node->l; return node; }
    Node* remove(Node* node, int x) {
        if(!node) return nullptr;
        if(x < node->val) node->l = remove(node->l, x);
        else if(x > node->val) node->r = remove(node->r, x);
        else {
            if(!node->l) { Node* r = node->r; delete node; return r; }
            if(!node->r) { Node* l = node->l; delete node; return l; }
            Node* succ = findMin(node->r);
            node->val = succ->val;
            node->r = remove(node->r, succ->val);
        }
        return node;
    }
    bool search(Node* node, int x) { if(!node) return false; if(node->val == x) return true; if(x < node->val) return search(node->l, x); return search(node->r, x); }
    void inorder(Node* node) { if(!node) return; inorder(node->l); cout << node->val << " "; inorder(node->r); }
    void preorder(Node* node) { if(!node) return; cout << node->val << " "; preorder(node->l); preorder(node->r); }
    void postorder(Node* node) { if(!node) return; postorder(node->l); postorder(node->r); cout << node->val << " "; }
public:
    BST(): root(nullptr) {}
    void insert(int x) { root = insert(root, x); cout << "Inserted " << x << "\n"; }
    void remove(int x) { root = remove(root, x); cout << "Requested removal of " << x << "\n"; }
    void searchAndReport(int x) { cout << (search(root, x) ? ("Found " + to_string(x) + "\n") : (to_string(x) + " not found\n")); }
    void displayInorder() { cout << "Inorder: "; inorder(root); cout << "\n"; }
    void displayPreorder() { cout << "Preorder: "; preorder(root); cout << "\n"; }
    void displayPostorder() { cout << "Postorder: "; postorder(root); cout << "\n"; }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    BST tree; cout << "----- BST DEMO -----\n";
    vector<int> vals = {50, 30, 20, 40, 70, 60, 80};
    for(int v: vals) tree.insert(v);
    tree.displayInorder();
    tree.displayPreorder();
    tree.displayPostorder();
    tree.searchAndReport(60);
    tree.remove(50);
    tree.displayInorder();
    tree.displayPreorder();
    tree.displayPostorder();
    tree.searchAndReport(50);
    return 0;
}
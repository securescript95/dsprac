#include <bits/stdc++.h>
using namespace std;
struct Node { int data; Node* next; Node(int d): data(d), next(nullptr) {} };
class CircularLinkedList {
    Node* tail;
public:
    CircularLinkedList(): tail(nullptr) {}
    ~CircularLinkedList() {
        if(!tail) return;
        Node* head = tail->next;
        tail->next = nullptr;
        while(head) { Node* t = head; head = head->next; delete t; }
    }
    void insert(int x) {
        Node* n = new Node(x);
        if(!tail) { tail = n; tail->next = tail; cout << "Inserted " << x << " as the only element\n"; return; }
        n->next = tail->next;
        tail->next = n;
        tail = n;
        cout << "Inserted " << x << " at end (circular)\n";
    }
    void remove(int x) {
        if(!tail) { cout << "List empty\n"; return; }
        Node *cur = tail->next, *prev = tail;
        do {
            if(cur->data == x) {
                if(cur == prev) { cout << "Removed " << x << " (list becomes empty)\n"; delete cur; tail = nullptr; return; }
                prev->next = cur->next;
                if(cur == tail) tail = prev;
                cout << "Removed " << x << "\n"; delete cur; return;
            }
            prev = cur; cur = cur->next;
        } while(cur != tail->next);
        cout << x << " not found\n";
    }
    Node* search(int x) {
        if(!tail) { cout << "List empty\n"; return nullptr; }
        Node* cur = tail->next; int pos = 1;
        do { if(cur->data == x) { cout << "Found " << x << " at position " << pos << "\n"; return cur; } cur = cur->next; pos++; } while(cur != tail->next);
        cout << x << " not found\n"; return nullptr;
    }
    void display() {
        if(!tail) { cout << "Circular List: Empty\n"; return; }
        cout << "Circular List: ";
        Node* cur = tail->next;
        bool first = true;
        do { if(!first) cout << " -> "; cout << cur->data; first = false; cur = cur->next; } while(cur != tail->next);
        cout << "\n";
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    CircularLinkedList cll;
    cout << "----- CIRCULAR LINKED LIST DEMO -----\n";
    cll.insert(10);
    cll.insert(20);
    cll.insert(30);
    cll.display();
    cll.search(20);
    cll.remove(20);
    cll.display();
    cll.remove(99);
    cll.remove(10);
    cll.remove(30);
    cll.display();
    return 0;
}
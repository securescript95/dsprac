#include <bits/stdc++.h>
using namespace std;
struct Node { int data; Node *prev, *next; Node(int d): data(d), prev(nullptr), next(nullptr) {} };
class DoublyLinkedList {
    Node *head, *tail;
public:
    DoublyLinkedList(): head(nullptr), tail(nullptr) {}
    ~DoublyLinkedList() { while(head) { Node *t = head; head = head->next; delete t; } }
    void insertBeginning(int x) { Node *n = new Node(x); n->next = head; if(head) head->prev = n; head = n; if(!tail) tail = head; cout << "Inserted " << x << " at beginning\n"; }
    void insertEnd(int x) { Node *n = new Node(x); n->prev = tail; if(tail) tail->next = n; tail = n; if(!head) head = tail; cout << "Inserted " << x << " at end\n"; }
    void removeBeginning() { if(!head) { cout << "List empty\n"; return; } Node *t = head; head = head->next; if(head) head->prev = nullptr; else tail = nullptr; cout << "Removed " << t->data << " from beginning\n"; delete t; }
    void removeEnd() { if(!tail) { cout << "List empty\n"; return; } Node *t = tail; tail = tail->prev; if(tail) tail->next = nullptr; else head = nullptr; cout << "Removed " << t->data << " from end\n"; delete t; }
    void displayForward() { cout << "Forward: "; Node *cur = head; if(!cur) { cout << "Empty\n"; return; } while(cur) { cout << cur->data; if(cur->next) cout << " <-> "; cur = cur->next; } cout << "\n"; }
    void displayBackward() { cout << "Backward: "; Node *cur = tail; if(!cur) { cout << "Empty\n"; return; } while(cur) { cout << cur->data; if(cur->prev) cout << " <-> "; cur = cur->prev; } cout << "\n"; }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    DoublyLinkedList dll;
    cout << "----- DOUBLY LINKED LIST DEMO -----\n";
    dll.insertBeginning(20);
    dll.insertEnd(40);
    dll.insertBeginning(10);
    dll.insertEnd(50);
    dll.displayForward();
    dll.displayBackward();
    dll.removeBeginning();
    dll.displayForward();
    dll.removeEnd();
    dll.displayForward();
    dll.removeEnd();
    dll.removeEnd();
    dll.removeEnd();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
struct Node { int data; Node *next; Node(int d): data(d), next(nullptr) {} };
class SinglyLinkedList {
    Node *head;
public:
    SinglyLinkedList(): head(nullptr) {}
    ~SinglyLinkedList() { while(head) { Node *t = head; head = head->next; delete t; } }
    void insertAtBeginning(int x) { Node *n = new Node(x); n->next = head; head = n; cout << "Inserted " << x << " at beginning\n"; }
    void insertAtPosition(int x, int pos) {
        if(pos <= 1) { insertAtBeginning(x); return; }
        Node *cur = head; int idx = 1;
        while(cur && idx < pos-1) { cur = cur->next; idx++; }
        if(!cur) {
            cout << "Position out of bounds. Inserting at end.\n";
            Node *n = new Node(x);
            if(!head) head = n;
            else { Node *t = head; while(t->next) t = t->next; t->next = n; }
            cout << "Inserted " << x << " at end\n";
            return;
        }
        Node *n = new Node(x); n->next = cur->next; cur->next = n;
        cout << "Inserted " << x << " at position " << pos << "\n";
    }
    void removeFromBeginning() { if(!head) { cout << "List empty\n"; return; } Node *t = head; head = head->next; cout << "Removed " << t->data << " from beginning\n"; delete t; }
    void removeFromPosition(int pos) {
        if(!head) { cout << "List empty\n"; return; }
        if(pos <= 1) { removeFromBeginning(); return; }
        Node *cur = head; int idx = 1;
        while(cur->next && idx < pos-1) { cur = cur->next; idx++; }
        if(!cur->next) { cout << "Position out of bounds\n"; return; }
        Node *t = cur->next; cur->next = t->next; cout << "Removed " << t->data << " from position " << pos << "\n"; delete t;
    }
    Node* search(int x) { Node *cur = head; int pos = 1; while(cur) { if(cur->data == x) { cout << "Found " << x << " at position " << pos << "\n"; return cur; } cur = cur->next; pos++; } cout << x << " not found\n"; return nullptr; }
    void display() { cout << "List: "; Node *cur = head; if(!cur) { cout << "Empty\n"; return; } while(cur) { cout << cur->data; if(cur->next) cout << " -> "; cur = cur->next; } cout << "\n"; }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    SinglyLinkedList sll;
    cout << "----- SINGLY LINKED LIST DEMO -----\n";
    sll.insertAtBeginning(30);
    sll.insertAtBeginning(20);
    sll.insertAtBeginning(10);
    sll.display();
    sll.insertAtPosition(25, 3);
    sll.display();
    sll.search(25);
    sll.removeFromBeginning();
    sll.display();
    sll.removeFromPosition(3);
    sll.display();
    sll.search(100);
    return 0;
}
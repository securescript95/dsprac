#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Queue {
    struct Node { T val; Node* next; Node(T v): val(v), next(nullptr) {} };
    Node *frontNode, *rearNode;
public:
    Queue(): frontNode(nullptr), rearNode(nullptr) {}
    ~Queue() { while(frontNode) { Node* t = frontNode; frontNode = frontNode->next; delete t; } }
    bool empty() const { return frontNode == nullptr; }
    void enqueue(T x) { Node* n = new Node(x); if(rearNode) rearNode->next = n; rearNode = n; if(!frontNode) frontNode = rearNode; cout << "Enqueued " << x << "\n"; }
    T dequeue() { if(!frontNode) throw runtime_error("Queue empty"); Node* t = frontNode; T v = t->val; frontNode = frontNode->next; if(!frontNode) rearNode = nullptr; delete t; cout << "Dequeued " << v << "\n"; return v; }
    T front() const { if(!frontNode) throw runtime_error("Queue empty"); return frontNode->val; }
    void display() const { cout << "Queue: "; Node* cur = frontNode; if(!cur) { cout << "Empty\n"; return; } while(cur) { cout << cur->val; if(cur->next) cout << " <- "; cur = cur->next; } cout << "\n"; }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << "----- QUEUE DEMO -----\n";
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    q.enqueue(40);
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    try { q.dequeue(); } catch(const exception &e) { cout << "Exception: " << e.what() << "\n"; }
    return 0;
}
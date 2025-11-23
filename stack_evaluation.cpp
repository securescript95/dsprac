#include <bits/stdc++.h>
using namespace std;
class Stack { vector<long long> a; public: bool empty() const { return a.empty(); } void push(long long x) { a.push_back(x); } long long pop() { long long v = a.back(); a.pop_back(); return v; } long long top() const { return a.back(); } };
long long applyOp(long long a, long long b, char op) {
    if(op == '+') return a + b;
    if(op == '-') return a - b;
    if(op == '*') return a * b;
    if(op == '/') return a / b;
    if(op == '^') return (long long) pow((double)a, (double)b);
    return 0;
}
long long evalPostfix(const string &expr) {
    Stack st; stringstream ss(expr); string token;
    while(ss >> token) {
        if(isdigit(token[0]) || (token.size()>1 && token[0]=='-' && isdigit(token[1]))) st.push(stoll(token));
        else { long long b = st.pop(); long long a = st.pop(); st.push(applyOp(a,b,token[0])); }
    }
    return st.pop();
}
long long evalPrefix(const string &expr) {
    vector<string> tokens; stringstream ss(expr); string token;
    while(ss >> token) tokens.push_back(token);
    Stack st;
    for(int i = (int)tokens.size()-1; i >= 0; --i) {
        token = tokens[i];
        if(isdigit(token[0]) || (token.size()>1 && token[0]=='-' && isdigit(token[1]))) st.push(stoll(token));
        else { long long a = st.pop(); long long b = st.pop(); st.push(applyOp(a,b,token[0])); }
    }
    return st.pop();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << "----- STACK EVALUATION DEMO -----\n";
    string postfix = "2 3 1 * + 9 -";
    cout << "Postfix: " << postfix << "\n";
    cout << "Postfix evaluation result: " << evalPostfix(postfix) << "\n\n";
    string prefix = "- + 2 * 3 1 9";
    cout << "Prefix: " << prefix << "\n";
    cout << "Prefix evaluation result: " << evalPrefix(prefix) << "\n";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

stack<int> s;

void traverse(Node *root) {
    if (root != NULL) {
        s.push(root->data);
        traverse(root->right);
        traverse(root->left);
    }
} 

void postOrder(Node *root) {
    traverse(root);
    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
}
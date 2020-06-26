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

vector<int> result;
queue <Node*> q;

void levelOrder(Node * root) { 
    q.push(root);
    traverse(root);
    for(int i=0;i<result.size();i++) {
        cout<<result[i];
        if (i < result.size() - 1) {
            cout<<" ";
        }
    }
    cout<<endl;
}

void traverse(Node* root) {
    while(!q.empty()) {
        Node* curr = q.front();
        result.push_back(curr->data);
        q.pop();
        if (curr->left != NULL) {
            q.push(curr->left);
        } 
        if (curr->right != NULL) {
            q.push(curr->right);
        }
    }
}

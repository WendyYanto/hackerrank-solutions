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

void inOrder(Node *root) {
    if (root->left != NULL) {
        inOrder(root->left);
    }
    cout<<root->data<<" ";
    if (root->right != NULL) {
        inOrder(root->right);
    }
}
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

bool checkBST(Node* root) {
    return checkBSTAgain(root, -2147483647, 2147483647);
}

bool checkBSTAgain(Node* root, int min, int max) {
    if (root == NULL) {
        return true;
    }
    if (!(min < root->data && root->data < max)) {
        return false;
    }
    return checkBSTAgain(root->left, min, root->data) && checkBSTAgain(root->right, root->data, max);
}
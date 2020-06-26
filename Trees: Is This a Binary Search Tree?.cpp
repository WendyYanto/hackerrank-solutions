// Will Have Acc if Only can include #set
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

vector<int> list;

void traverse(Node* root) {
    if (root == NULL) {
        return;
    }
    if (root->left != NULL) {
        list.push_back(root->left->data);
        traverse(root->left);
    } 
    if (root->right != NULL) {
        list.push_back(root->right->data);
        traverse(root->right);
    }
}

bool checkBST(Node* root) {
    if (root == NULL) {
        return true;
    }
    int data = root->data;
    traverse(root->left);
    int size = list.size();
    for(int i=0;i<size;i++) {
        if (list[i] >= data) {
            return false;
        }
    }
    traverse(root->right);
    int updatedSize = list.size();
    for(int i=size;i<updatedSize;i++) {
        if (list[i] <= data) {
            return false;
        }
    }
    list.clear();
    return checkBST(root->left) && checkBST(root->right);
}
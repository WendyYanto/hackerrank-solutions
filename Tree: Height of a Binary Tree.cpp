
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
  int max(int a, int b){
      if(a>b){
          return a;
      }
      return b;
  }

  int height(Node* root) {
      if (root == NULL) {
          return -1;
      }
      return 1 + max(height(root->left), height(root->right));
      // Write your code here.
  }

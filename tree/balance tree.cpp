/* A binary tree node structure

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
 */

class Solution {
  public:
    int height(Node* root, bool &valid)
    {
        if(root==NULL)
            return 0;
        int l = height(root->left, valid);
        int r = height(root->right, valid);
        
        if(abs(l-r) > 1)
        {
            valid = 0;
        }
        return 1 + max(l, r);
    }
    bool isBalanced(Node* root) {
        // Code here
        bool valid = 1;
        height(root, valid);
        return valid;
    }
};

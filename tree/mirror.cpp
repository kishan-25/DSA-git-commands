/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

// cheange the reference not the data

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirr(Node* root)
    {
        if(root == NULL)
            return;
        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirr(root->left);
        mirr(root->right);
    }
    void mirror(Node* node) {
        // code here
        mirr(node);
    }
};

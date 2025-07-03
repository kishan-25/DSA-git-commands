  int height(Node* root)
    {
        if(root == NULL)
            return NULL;
        return 1 + max(height(root->left), height(root->right));
        
    }

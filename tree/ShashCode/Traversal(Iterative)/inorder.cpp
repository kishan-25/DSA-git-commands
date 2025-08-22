class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* node = root;
        while(node != NULL || !s.empty())
        {
            // move left as far as possible
            while(node != NULL)
            {
                s.push(node);
                node = node->left;
            }

            // process current node
            node = s.top();
            s.pop();
            ans.push_back(node->val);

            // move to right subtree
            node = node->right;
        }
        return ans;
    }
};

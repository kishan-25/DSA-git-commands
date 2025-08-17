/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void check(TreeNode* l, TreeNode* r, bool &isSym)
    {
        if(l == NULL && r == NULL)
            return;
        if(l == NULL || r == NULL)
        {
            isSym = false;
            return;
        }
        if(l->val != r->val)
        {
            isSym = false;
            return;
        }
        check(l->left, r->right, isSym);
        check(l->right, r->left, isSym);
    }
    bool isSymmetric(TreeNode* root) {
        bool isSym = true;
        check(root->left, root->right, isSym);
        return isSym;
    }
};

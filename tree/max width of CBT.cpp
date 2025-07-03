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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>> q;
        unsigned long long maxwidth = 0;
        q.push({root, 0});
        while(!q.empty())
        {
            int size = q.size();
            unsigned long long  strindx = q.front().second;
            unsigned long long  endindx = q.back().second;
            maxwidth = max(maxwidth,(endindx-strindx+1));
            for(int i=0;i<size;i++)
            {
                TreeNode* node = q.front().first;
                unsigned long long indx = q.front().second;
                q.pop();
                if(node->left)
                {
                    q.push({node->left, 2*indx+1});
                }
                if(node->right)
                {
                    q.push({node->right, 2*indx+2});
                }
            } 
        }
        return (int)(maxwidth);
    }
};

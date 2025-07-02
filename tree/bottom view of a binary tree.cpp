/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Your Code Here
        queue<pair<Node*, int>> q;
        map<int, int> mp;
        q.push({root, 0});
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                Node* node = q.front().first;
                int level = q.front().second;
                q.pop();
                
                mp[level] = node->data;
                
                if(node->left)
                {
                    q.push({node->left, level-1});
                }
                if(node->right)
                {
                    q.push({node->right, level+1});
                }
            }
        }
        vector<int> ans;
        for(auto ele : mp)
        {
            ans.push_back(ele.second);
        }
        return ans;
    }
};

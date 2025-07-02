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
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                Node* node = q.front().first;
                int level = q.front().second;
                q.pop();
                if(mp.find(level) == mp.end())
                {
                    mp.insert({level, node->data});
                }
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

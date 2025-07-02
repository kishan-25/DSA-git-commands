/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        queue<Node*> q;
        q.push(root);
        vector<int>ans;
        if(root == NULL)
            return ans;
        while(!q.empty())
        {
            int size = q.size();
            Node* node = q.front();
            int first = node->data;
            ans.push_back(first);
            for(int i=0;i<size;i++)
            {
                Node* node = q.front();
                q.pop();
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
        }
        return ans;
    }
};

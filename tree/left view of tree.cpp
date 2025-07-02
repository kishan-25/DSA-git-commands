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

// using recursion

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
    int height(Node* root)
    {
        if(root == NULL)
            return NULL;
        return 1 + max(height(root->left), height(root->right));
        
    }
    void find(Node* root, vector<int> &ans, vector<bool> &visited, int level)
    {
        if(root == NULL)
            return;
        
        if(visited[level] == 0)
        {
            ans.push_back(root->data);
            visited[level] = 1; 
        }
        find(root->left, ans, visited, level+1);
        find(root->right, ans, visited, level+1);
    }
    vector<int> leftView(Node *root) {
        // code here
       int levels = height(root);
       vector<bool>visited(levels,0);
       vector<int> ans;
       int level = 0;
       find(root, ans, visited, level);
       return ans;
    }
};

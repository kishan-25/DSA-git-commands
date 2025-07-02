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
    // Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2) {
        // Your Code here
        queue<Node*> q1;
        q1.push(r1);
        queue<Node*> q2;
        q2.push(r2);
        while(!q1.empty() && !q2.empty())
        {
            int size1 = q1.size();
            int size2 = q2.size();
            if(size1 != size2)
                return false;
            for(int i=0;i<size1;i++)
            {
                Node* node1 = q1.front();
                q1.pop();
                Node* node2 = q2.front();
                q2.pop();
                if(node1->data != node2->data)
                {
                    return false;
                }
                if(node1->left && node2->left)
                {
                    q1.push(node1->left);
                    q2.push(node2->left);
                }
                else if(node1->left != NULL || node2->left != NULL)
                {
                    return false;
                }
                if(node1->right && node2->right)
                {
                    q1.push(node1->right);
                    q2.push(node2->right);
                }
                else if(node1->right != NULL || node2->right != NULL)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
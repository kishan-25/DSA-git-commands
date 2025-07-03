class Solution {
  public:
    bool isCousins(Node* root, int x, int y) {
        if (!root) return false;

        queue<Node*> q;
        q.push(root);

        int depth = 0;
        int depthx = -1, depthy = -1;
        int parentx = -1, parenty = -1;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();

                if (node->left) {
                    if (node->left->data == x) {
                        parentx = node->data;
                        depthx = depth + 1;
                    }
                    if (node->left->data == y) {
                        parenty = node->data;
                        depthy = depth + 1;
                    }
                    q.push(node->left);
                }

                if (node->right) {
                    if (node->right->data == x) {
                        parentx = node->data;
                        depthx = depth + 1;
                    }
                    if (node->right->data == y) {
                        parenty = node->data;
                        depthy = depth + 1;
                    }
                    q.push(node->right);
                }
            }
            depth++;
        }

        // Check for cousin condition
        return (depthx == depthy && parentx != parenty);
    }
};

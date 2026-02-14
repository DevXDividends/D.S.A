// TC:O(n) SC:O(n) 
class Solution {
public:
    TreeNode* bfsToParent(TreeNode* root,
                          unordered_map<TreeNode*, TreeNode*>& parent,
                          int start) {

        queue<TreeNode*> q;
        q.push(root);
        TreeNode* target = nullptr;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->val == start)
                target = node;

            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }

            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        return target;
    }

    int infect(TreeNode* start, unordered_map<TreeNode*, TreeNode*>& parent) {

        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;

        q.push(start);
        visited[start] = true;

        int time_taken = 0;

        while (!q.empty()) {
            int size = q.size();
            bool flag = false;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = true;
                    flag = true;
                }

                if (node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right] = true;
                    flag = true;
                }

                if (parent[node] && !visited[parent[node]]) {
                    q.push(parent[node]);
                    visited[parent[node]] = true;
                    flag = true;
                }
            }

            if (flag)
                time_taken++;
        }

        return time_taken;
    }

    int amountOfTime(TreeNode* root, int start) {

        unordered_map<TreeNode*, TreeNode*> parent;

        TreeNode* startNode = bfsToParent(root, parent, start);

        return infect(startNode, parent);
    }
};

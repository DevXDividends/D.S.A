// TC:O(n) SC:O(n)
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        int ans = 0;
        while (!q.empty()) {
            int size = q.size();
            int minimum_value = q.front().second;
            int first, last;
            for (int i = 0; i < size; i++) {
                long long  curr_index = q.front().second - minimum_value;
                TreeNode* node = q.front().first;
                q.pop();
                if (i == 0)
                    first = curr_index;
                if (i == size - 1)
                    last = curr_index;
                if (node->left)
                    q.push({node->left, 2 * curr_index + 1});
                if (node->right)
                    q.push({node->right, 2 * curr_index + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};

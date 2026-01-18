// TC:O(n) SC:O(n) 
class Solution {
public:
    void find(TreeNode*& root, int level, vector<vector<int>>& ans) {
        if (!root)
            return;
        if (ans.size() <= level)
            ans.push_back({});
        ans[level].emplace_back(root->val);
        // left
        find(root->left, level + 1, ans);
        // right
        find(root->right, level + 1, ans);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        find(root, 0, ans);
        for (int i = 1; i < ans.size(); i++) {
            if (i % 2 == 0)
                continue;
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};

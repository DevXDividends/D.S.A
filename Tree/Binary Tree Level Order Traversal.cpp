TC:O(n) SC:O(n)
class Solution {
public:
    void findLevel(TreeNode*& root, int level, vector<vector<int>>& res) {
        if (!root)
            return;
        if (res.size() <= level)
            res.push_back({});
        res[level].emplace_back(root->val);
        // call for left
        findLevel(root->left, level + 1, res);
        // call for right
        findLevel(root->right, level + 1, res);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        findLevel(root, 0, ans);
        return ans;
    }
};

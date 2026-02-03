// TC:O(n) SC:O(n) 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};
        vector<int> ans;
        queue<pair<TreeNode*, int>> q;
        map<int, int> mpp;
        q.push({root, 0});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int row = it.second;
            mpp[row] = it.first->val;

            if (it.first->left)
                q.push({it.first->left, row + 1});
            if (it.first->right)
                q.push({it.first->right, row + 1});
        }
        for (auto& n : mpp)
            ans.emplace_back(n.second);
        return ans;
    }
};

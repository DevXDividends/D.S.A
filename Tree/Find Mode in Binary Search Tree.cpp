// Recursive TC:O(n) SC:O(n)
class Solution {
public:
    void dfs(TreeNode* root, unordered_map<int, int>& counter) {
        if (!root)
            return;
        counter[root->val]++;
        dfs(root->left, counter);
        dfs(root->right, counter);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> counter;
        dfs(root, counter);
        vector<int> ans;
        int maxval = INT_MIN;
        for (auto& c : counter)
            maxval = max(maxval, c.second);

        for (auto& c : counter)
            if (c.second == maxval)
                ans.emplace_back(c.first);
        return ans;
    }
};
// Iterative TC:O(n) SC:O(n) 
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> counter;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            counter[node->val]++;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        int maxval = INT_MIN;
        for (auto& c : counter)
            maxval = max(maxval, c.second);

        vector<int> ans;
        for (auto& c : counter)
            if (c.second == maxval)
                ans.emplace_back(c.first);
        return ans;
    }
};

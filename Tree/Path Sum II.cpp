/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void f(TreeNode* root, int currSum, vector<int>& path,
           vector<vector<int>>& ans, int& targetSum) {
        if (!root)
            return;
        path.emplace_back(root->val);
        currSum += root->val;

        if (currSum == targetSum && root->left == nullptr &&
            root->right == nullptr) {
            ans.emplace_back(path);

        } else {

            f(root->left, currSum, path, ans, targetSum);
            f(root->right, currSum, path, ans, targetSum);
        }
        path.pop_back();
        currSum -= root->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return {};
        vector<vector<int>> ans;
        vector<int> path;
        f(root, 0, path, ans, targetSum);
        return ans;
    }
};

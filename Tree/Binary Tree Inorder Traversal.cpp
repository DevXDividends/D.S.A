// TC:O(n) SC:(h) 
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
    void fun(TreeNode*& root, vector<int>& ans) {
        // Inorder: Left->root->Right
        if (!root)
            return;
        fun(root->left, ans);
        ans.emplace_back(root->val);
        fun(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root)
            return {};
        vector<int> ans;

        fun(root, ans);

        return ans;
    }
};

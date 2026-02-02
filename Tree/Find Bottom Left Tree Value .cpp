// TC:O(n) SC:O(h)
class Solution {
public:
    void findAns(TreeNode* &root, int height, int &maxHeight, int &ans) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            if (height > maxHeight) {
                maxHeight = height;
                ans = root->val;
            }
            return;
        }
        findAns(root->left, height + 1, maxHeight, ans);
        findAns(root->right, height + 1, maxHeight, ans);
    }
    int findBottomLeftValue(TreeNode* root) {
        int ans = -1;
        if (!root)
            return ans;
            int maxHeight = -1;
        findAns(root, 0, maxHeight, ans);
        return ans;
    }
};

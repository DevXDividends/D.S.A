// TC:O(n) SC:O(n)
class Solution {
public:
    int height(TreeNode*& root, int& maxi) {
        if (!root)
            return 0;
        int lh{height(root->left, maxi)};
        int rh{height(root->right, maxi)};
        maxi = max(maxi, lh + rh);
        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};

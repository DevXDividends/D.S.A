// TC:O(n) SC:O(h)
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        int left{minDepth(root->left)};
        int right(minDepth(root->right));

        if (root->left==nullptr || root->right==nullptr)
            return 1 +  max(left, right);

        return 1 + min(left,right);
    }
};

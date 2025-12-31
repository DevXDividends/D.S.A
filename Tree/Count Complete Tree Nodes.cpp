// TC:O(n) SC:O(H)
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        if(!root->left && !root->right)return 1;
        int left(countNodes(root->left));
        int right(countNodes(root->right));
        return 1+left + right;;
    }
};

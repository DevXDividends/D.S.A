// TC:O(n) SC:O(n) 
class Solution {
public:
    bool checkIfSymmetric(TreeNode* left, TreeNode* right) {
        if (!left || !right)
            return left == right;
        if (left->val != right->val)
            return false;
        return checkIfSymmetric(left->left, right->right) &&
               checkIfSymmetric(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return root == nullptr || checkIfSymmetric(root->left, root->right);
    }
};

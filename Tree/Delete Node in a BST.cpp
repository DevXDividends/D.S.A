// TC:O(h) SC:O(h)
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
    TreeNode*  getSuccessor(TreeNode * &root) {
        TreeNode* curr = root->right;
        while (curr != nullptr && curr->left != nullptr)
            curr = curr->left;
        return curr;
    }
    TreeNode* DeleteTreeNode(TreeNode*& root, int val) {
        if (!root)
            return nullptr;
        if (val < root->val) {
            root->left = DeleteTreeNode(root->left, val);
        } else if (val > root->val) {
            root->right = DeleteTreeNode(root->right, val);
        } else {
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            if (root->right ==  nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            TreeNode* SuccNode =getSuccessor(root);
            root->val = SuccNode->val;
            root->right=DeleteTreeNode(root->right,root->val);
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return DeleteTreeNode(root,key);
    }
};

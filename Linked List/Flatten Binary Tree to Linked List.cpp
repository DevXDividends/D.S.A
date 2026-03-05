brute TC:O(n) SC:O(n)
class Solution {
public:
    void collectValues(TreeNode*& root, vector<TreeNode*>& arr) {
        if (!root)
            return;
        ;
        arr.emplace_back(root);
        collectValues(root->left, arr);
        collectValues(root->right, arr);
    }

    void flatten(TreeNode* root) {
        vector<TreeNode*> arr;
        collectValues(root, arr);
        TreeNode* dummy = new TreeNode(-1);
        TreeNode* curr = dummy;
        for (int i = 0; i < arr.size(); i++) {
            curr->right = arr[i];

            curr = curr->right;
            curr->left = nullptr;
        }
    }
};
optimal TC:O(n) SC:O(1)
  class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr) {
            if (curr->left) {
                TreeNode* temp = curr->left;
                while (temp->right) {
                    temp = temp->right;
                }
                temp->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};

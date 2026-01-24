// TC:O(n) SC:O(n) 
class Solution {
public:
    int findSum(TreeNode*& root, int& maxi) {
        if (!root)
            return 0;
        int leftSum = max(0, findSum(root->left, maxi));
        int rightSum = max(0, findSum(root->right, maxi));
        maxi = max(maxi, root->val + leftSum + rightSum);

        return root->val + max(leftSum, rightSum);
    }
    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0;
        int max_path_sum = std::numeric_limits<int>::min(); // assign the most negative value of int  or simply use INT_MIN
        findSum(root, max_path_sum);
        return max_path_sum;
    }
};

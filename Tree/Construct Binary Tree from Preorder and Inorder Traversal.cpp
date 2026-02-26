// TC:O(n) SC:O(n)
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        int size = inorder.size();

        for (int i = 0; i < size; i++)
            inMap[inorder[i]] = i;
        TreeNode* root =
            build(preorder, 0, preorder.size() - 1, inMap, 0, size - 1);
        return root;
    }
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                    unordered_map<int, int>& inMap, int inStart, int inEnd) {

        if (preStart > preEnd || inStart > inEnd)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;
        root->left = build(preorder, preStart + 1, preStart + numsLeft + 1,
                           inMap, inStart, inRoot - 1);
        root->right = build(preorder, preStart + numsLeft + 1, preEnd, inMap,
                            inRoot + 1, inEnd);
        return root;
    }
};

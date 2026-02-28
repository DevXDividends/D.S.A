// O:(n) SC:O(n) 
class Solution {
public:
    TreeNode* buildTree(vector<int>& postorder, int postStart, int postEnd,
                        unordered_map<int, int>& inMap, int inStart,
                        int inEnd) {
        if (postStart > postEnd || inStart > inEnd)
            return nullptr;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;
        // LEFT
        root->left = buildTree(postorder,
                               postStart,
                               postStart + numsLeft - 1,
                               inMap,
                               inStart,
                               inRoot - 1);

        // RIGHT
        root->right = buildTree(postorder,
                                postStart + numsLeft,
                                postEnd - 1,
                                inMap,
                                inRoot + 1,
                                inEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap;
        int size = inorder.size();
        for (int i = 0; i < size; i++)
            inMap[inorder[i]] = i;

        return buildTree(postorder, 0, postorder.size() - 1, inMap, 0, size - 1);

    }
};

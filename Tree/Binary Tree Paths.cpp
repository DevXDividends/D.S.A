// TC:O(n) SC:O(n)
class Solution {
public:
    bool isLeaf(TreeNode* node) {
        return node->left == nullptr && node->right == nullptr;
    }
    void find(TreeNode* root, vector<string>& ds, vector<string>& ans) {
        if (!root)
            return;
        ds.emplace_back(to_string(root->val));
        if (isLeaf(root)) {
            string s;
            for (int i = 0; i < ds.size(); i++) {
                s += ds[i];
                if (i + 1 < ds.size())
                    s += "->";
            }
            ans.emplace_back(s);
        } else {
            find(root->left, ds, ans);
            find(root->right, ds, ans);
        }
        ds.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        vector<string> ds;
        find(root, ds, ans);
        return ans;
    }
};

// TC:O(n log n) SC:O(n)
class Solution {
public:
    void verticalTrav(TreeNode* root, map<int, map<int, multiset<int>>>& hash,
                      int row, int col) {
        if (!root)
            return;
        hash[col][row].insert(root->val);
        verticalTrav(root->left, hash, row + 1, col - 1);
        verticalTrav(root->right, hash, row + 1, col + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        map<int, map<int, multiset<int>>> hash;

        verticalTrav(root, hash, 0, 0);
        for (const auto& col : hash) {
            vector<int> column;
            for (const auto& row : col.second)
                for (int val : row.second)
                    column.emplace_back(val);
            ans.emplace_back(column);
        }

        return ans;
    }
};

// TC:O(V x E) SC:O(V)
class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> ans(row, 0);
        for (int i = 0; i < row; i++) {
            for (int j = i+1; j < col; j++) {
                if (matrix[i][j] ) {
                    ans[i]++;
                    ans[j]++;
                }
            }
        }
        return ans;
    }
};

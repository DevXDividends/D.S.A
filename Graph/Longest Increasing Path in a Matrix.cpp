// TC:O(M x N) SC:O(M x N)
class Solution {
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

public:
    int dfs(int row, int col, vector<vector<int>>& mat,
            vector<vector<int>>& memo) {

        if (memo[row][col] != 0)
            return memo[row][col];
        int n = mat.size();
        int m = mat[0].size();

        int longest = 1;

        for (int i = 0; i < 4; i++) {
            int newr = row + dr[i];
            int newc = col + dc[i];

            if (newr < 0 || newr >= n || newc < 0 || newc >= m ||
                mat[newr][newc] <= mat[row][col])
                continue;
            int val = 1 + dfs(newr, newc, mat, memo);
            longest = max(longest, val);
        }
        return memo[row][col] = longest;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> memo(rows, vector<int>(cols, 0));

        int ans = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                ans = max(ans, dfs(i, j, matrix, memo));
            }
        }
        return ans;
    }
};

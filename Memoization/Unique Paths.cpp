// TC:O(N x M ) SC:O(N x M )
class Solution {
public:
    int find(int row, int col, int& rows, int& cols,
             vector<vector<int>>& memo) {
        if (row == rows - 1 && col == cols - 1) {
            return 1;
        }
        if (row < 0 || col < 0 || row >= rows || col >= cols)
            return 0;
        if (memo[row][col] != -1)
            return memo[row][col];
        int left = find(row, col + 1, rows, cols, memo);
        int right = find(row + 1, col, rows, cols, memo);
        memo[row][col] = left + right;
        return memo[row][col];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return find(0, 0, m, n, memo);
    }
};

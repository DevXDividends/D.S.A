// TC:O(N x M) SC:O(N x M)
class Solution {
public:
    int findPaths(int row, int col, vector<vector<int>>& playGround,
                  vector<vector<int>>& memo) {
        int n = playGround.size();
        int m = playGround[0].size();

        if (row < 0 || col < 0 || row >= n || col >= m ||
            playGround[row][col] == 1)
            return 0;

        if (row == n - 1 && col == m - 1)
            return 1;

        if (memo[row][col] != -1)
            return memo[row][col];

        int right = findPaths(row, col + 1, playGround, memo);
        int down = findPaths(row + 1, col, playGround, memo);

        memo[row][col] = right + down;
        return memo[row][col];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<vector<int>> memo(rows, vector<int>(cols, -1));
        return findPaths(0, 0, obstacleGrid, memo);
    }
};

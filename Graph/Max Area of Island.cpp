// TC:O(m x n) SC:O(m x n)
class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid,
             vector<vector<bool>>& vis, int& currArea) {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() ||
            vis[row][col])
            return;
        if (!grid[row][col])
            return;

        vis[row][col] = true;
        currArea++;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            dfs(row + dr[i], col + dc[i], grid, vis, currArea);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> vis(row, vector<bool>(col, false));
        int maxArea = 0;
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (grid[r][c] == 1 && !vis[r][c]) {
                    int currArea = 0;
                    dfs(r, c, grid, vis, currArea);
                    maxArea = max(maxArea, currArea);
                }
            }
        }
        return maxArea;
    }
};

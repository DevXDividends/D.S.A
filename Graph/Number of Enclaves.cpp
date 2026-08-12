// TC:O(N x M) SC:O(N x M)
class Solution {
private:
    int delrow[4] = {0, -1, 0, 1};
    int delcol[4] = {1, 0, -1, 0};

public:
    void dfs(int row, int col, vector<vector<int>>& grid,
             vector<vector<bool>>& vis, int& n, int& m) {
        vis[row][col] = true;
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] && grid[nrow][ncol])
                dfs(nrow, ncol, grid, vis, n, m);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int cnt = 0;
        vector<vector<bool>> vis(row, vector<bool>(col, false));
        for (int i = 0; i < col; i++) {

            if (grid[0][i] == 1 && !vis[0][i])
                dfs(0, i, grid, vis, row, col);

            if (grid[row - 1][i] == 1 && !vis[row-1][i])
                dfs(row - 1, i, grid, vis, row, col);
        }
        for (int i = 0; i < row; i++) {

            if (grid[i][0] == 1 && !vis[i][0])
                dfs(i, 0, grid, vis, row, col);
            
            if (grid[i][col - 1] == 1 && !vis[i][col - 1])
                dfs(i, col - 1, grid, vis, row, col);
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1 && !vis[i][j])
                    cnt++;
            }
        }
        return cnt;
    }
};

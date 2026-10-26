// TC:O(M x N) SC:O(M x N ) 
class Solution {
private:
    int dr[4] = {0, -1, 0, 1};
    int dc[4] = {1, 0, -1, 0};

public:
    long long  dfs(int row, int col, vector<vector<int>>& grid,
            vector<vector<bool>>& vis, int rows, int cols) {
        vis[row][col] = true;

        long long  currVal = grid[row][col];

        for (int i = 0; i < 4; i++) {

            int newr = row + dr[i];
            int newc = col + dc[i];

            if (newr >= 0 && newr < rows && newc >= 0 && newc < cols &&
                grid[newr][newc] != 0 && !vis[newr][newc])
                currVal += dfs(newr, newc, grid, vis, rows, cols);
        }
        return currVal;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        int cnt = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!vis[i][j] && grid[i][j]!=0) {
                    long long  val = dfs(i, j, grid, vis, rows, cols);
                    if (val % k == 0)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};

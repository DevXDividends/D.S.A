class Solution {
private:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

public:
    void traverse(int row, int col, vector<vector<int>>& grid,
                  vector<vector<bool>>& vis, int& cnt) {
        int n = grid.size();
        int m = grid[0].size();
        if (row < 0 || col < 0 || row >= n || col >= m ||
            grid[row][col] == -1 || vis[row][col])
            return;
        if (grid[row][col] == 2) {
            bool flag = true;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (!vis[i][j] && grid[i][j] != -1 && grid[i][j]!=2) {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) {
                cnt++;
                return;
            } else
                return;
        }
        vis[row][col] = true;
        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];
            if (nr < 0 || nc < 0 || nr >= n || nc >= m || grid[nr][nc] == -1 ||
                vis[nr][nc])
                continue;
            traverse(nr, nc, grid, vis, cnt);
        }
        vis[row][col] = false;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        int cnt = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1)
                    traverse(i, j, grid, vis, cnt);
            }
        }
        return cnt;
    }
};

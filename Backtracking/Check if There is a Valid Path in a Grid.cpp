// TC:O(N x M ) SC=O(nm)​
class Solution {
    int dr[4] = {0, 0, -1, 1};
    int dc[4] = {-1, 1, 0, 0};

public:
    bool check(int row, int col, vector<vector<int>>& grid,
               vector<vector<bool>>& vis, vector<vector<int>>& directions) {
        int n = grid.size();
        int m = grid[0].size();

        if (row < 0 || col < 0 || row >= n || col >= m || vis[row][col])
            return false;

        vis[row][col] = true;

        if (row == n - 1 && col == m - 1)
            return true;

        int type = grid[row][col];
        for (int dir : directions[type - 1]) {
            int nr = row + dr[dir];
            int nc = col + dc[dir];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                continue;

            // Check if the neighboring street connects back
            int opposite = (dir == 0) ? 1 : (dir == 1) ? 0 : (dir == 2) ? 3 : 2;

            int nextType = grid[nr][nc];

            bool connects = false;

            for (int d : directions[nextType - 1]) {
                if (d == opposite) {
                    connects = true;
                    break;
                }
            }

            if (connects && check(nr, nc, grid, vis, directions))
                return true;
        }

        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        vector<vector<int>> directions = {
            {0, 1}, // type 1: left, right
            {2, 3}, // type 2: up, down
            {0, 3}, // type 3: left, down
            {1, 3}, // type 4: right, down
            {0, 2}, // type 5: left, up
            {1, 2}  // type 6: right, up
        };
        return check(0, 0, grid, vis, directions);
    }
};

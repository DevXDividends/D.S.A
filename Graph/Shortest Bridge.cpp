// TC:O(N^2) SC:O(N^2) 
class Solution {
public:
    void marSecondIsland(int row, int col, vector<vector<int>>& grid,
                         vector<vector<bool>>& vis, int rows, int cols,
                         queue<pair<int, int>>& q) {
        if (row < 0 || row >= rows || col < 0 || col >= cols || vis[row][col] ||
            grid[row][col] == 0)
            return;
        vis[row][col] = true;
        q.push({row, col});
        marSecondIsland(row + 1, col, grid, vis, rows, cols, q);
        marSecondIsland(row, col - 1, grid, vis, rows, cols, q);
        marSecondIsland(row - 1, col, grid, vis, rows, cols, q);
        marSecondIsland(row, col + 1, grid, vis, rows, cols, q);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        bool marked = false;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] != 0) {
                    marSecondIsland(i, j, grid, vis, rows, cols, q);
                    marked = true;
                    break;
                }
            }
            if (marked)
                break;
        }

        int dist = 0;
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto [row, col] = q.front();
                q.pop();

                for (int j = 0; j < 4; j++) {
                    int newr = row + dr[j];
                    int newc = col + dc[j];

                    if (newr < 0 || newr >= rows || newc < 0 || newc >= cols ||
                        vis[newr][newc])
                        continue;

                    if (grid[newr][newc] == 1)
                        return dist;

                    vis[newr][newc] = true;
                    q.push({newr, newc});
                    
                }
            }
            dist++;
        }
        return dist;
    }
};

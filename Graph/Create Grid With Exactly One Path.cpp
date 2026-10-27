// TC:O(M x N) SC:O(M x N)
class Solution {
public:
    bool dfs(int row, int col, vector<vector<char>>& grid, int& m, int& n) {
        if (row < 0 || row >= m || col < 0 || col >= n)
            return false;
        if (row == m - 1 && col == n - 1){
            grid[row][col] = '.';
            return true;
        }
        char ch = grid[row][col];

        grid[row][col] = '.';
        if (dfs(row, col + 1, grid, m, n))
            return true;

        if (dfs(row + 1, col, grid, m, n))
            return true;

        grid[row][col] = ch;
        return false;
    }
    vector<string> createGrid(int m, int n) {
        vector<vector<char>> grid(m, vector<char>(n, '#'));
        bool exists = dfs(0, 0, grid, m, n);
        vector<string> path;
        for (int i = 0; i < m; i++) {
            string currPath = "";
            for (int j = 0; j < n; j++) {
                currPath += grid[i][j];
            }
            path.emplace_back(currPath);
        }
        return path;
    }
};

// TC:O(N x M) SC:O(N x M) 
class Solution {
	private:
	int dr[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
	int dc[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
	public:
	void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<bool>> &vis) {
		vis[row][col] = true;
		int n = grid.size();
		int m = grid[0].size();
		for (int i = 0; i<8; i++) {
			int newr = row + dr[i];
			int newc = col + dc[i];
			if (newr >= 0 && newr<n && newc >= 0 && newc<m && grid[newr][newc] == 'L'
			 && !vis[newr][newc])
			dfs(newr, newc, grid, vis);
		}
	}
	int countIslands(vector<vector<char>> & grid) {
		
		int rows = grid.size();
		int cols = grid[0].size();
		
		int cntIslands = 0;
		
		vector<vector<bool>> vis(rows, vector<bool> (cols, false));
		
		for (int i = 0; i<rows; i++) {
			for (int j = 0; j<cols; j++) {
				if (grid[i][j] == 'W')
					continue;
				if (!vis[i][j]) {
					dfs(i, j, grid, vis);
					cntIslands++;
				}
			}
		}
		return cntIslands;
		
	}
};

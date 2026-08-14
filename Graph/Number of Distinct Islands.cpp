// TC:O(NM log(NM)) SC:O(NM)
class Solution {
	private:
	
	int delrow[4] = {-1, 0, 1, 0};
	int delcol[4] = {0, 1, 0, -1};
	
	public:
	
	void dfs(int row, int col, vector<vector<char>> & grid,
	vector<vector<bool>> &vis, vector<pair<int, int>> &list, int row0, int col0) {
		
		vis[row][col] = true;
		list.push_back({row - row0, col - col0});
		
		int n = grid.size();
		int m = grid[0].size();
		
		for (int i = 0; i<4; i++) {
			int nrow = row + delrow[i];
			int ncol = col + delcol[i];
			
			if (nrow >= 0 && nrow<n && ncol >= 0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == 'L')
				dfs(nrow, ncol, grid, vis, list, row0, col0);
		}
		
	}
	int countDistinctIslands(vector<vector<char>> & grid) {
		// code here
		int rows = grid.size();
		int cols = grid[0].size();
		
		set<vector<pair<int, int>> > set;
		vector<vector<bool>> vis(rows, vector<bool>(cols, false));
		
		for (int i = 0; i<rows; i++) {
			for (int j = 0; j<cols; j++) {
				
				if (!vis[i][j] && grid[i][j] == 'L') {
					vector<pair<int, int>> list;
					
					dfs(i, j, grid, vis, list, i, j);
					set.insert(list);
				}
			}
		}
		return set.size();
		
	}
};

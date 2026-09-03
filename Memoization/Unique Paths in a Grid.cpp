// TC:O(N x M) SC:O(N x M)
class Solution {
	public:
	int find(int row, int col, vector<vector<int>> &grid,
	vector<vector<int>> & memo) {
		
		int n = grid.size();
		int m = grid[0].size();
		
		if (row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == 1)
			return 0;
			
		if (row == n - 1 && col == m - 1)
			return 1;

		if (memo[row][col] != -1)
			return memo[row][col];
		
		int left = find(row, col + 1, grid, memo);
		int right = find(row + 1, col, grid, memo);
		
		memo[row][col] = left + right;
		return memo[row][col];
	}
	int uniquePaths(vector<vector<int>> &grid) {
		// code here
		int rows = grid.size();
		int cols = grid[0].size();
		vector<vector<int>> memo(rows, vector<int>(cols, -1));
		
		return find(0, 0, grid, memo);
		
	}
};

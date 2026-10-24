// TC:O(N^2) SC:O(N^2) 
class Solution {
	int dr[4] = {0, -1, 0, 1};
	int dc[4] = {1, 0, -1, 0};
	
	public:
	
	bool findPath(int row, int col, vector<vector<int>> &mat, int &rows, int &cols) {
		
		if (mat[row][col] == 2)
			return true;
		
		int cell = mat[row][col];
		mat[row][col] = -1;
		
		for (int i = 0; i<4; i++) {
			int newr = row + dr[i];
			int newc = col + dc[i];
			
			if (newr >= 0 && newr<rows &&
			newc >= 0 && newc<cols && mat[newr][newc] != 0 && mat[newr][newc] != -1)
			
			if (findPath(newr, newc, mat, rows, cols)) {
				mat[row][col] = cell;
				return true;
			}
		}
		mat[row][col] = cell;
		return false;
		
	}
	bool isPathPossible(vector<vector<int>> & mat) {
		int rows = mat.size();
		int cols = mat[0].size();
		
		for (int i = 0; i<rows; i++) {
			for (int j = 0; j<cols; j++) {
				if (mat[i][j] == 1)
					if (findPath(i, j, mat, rows, cols))
						return true;
			}
		}
		return false;
		
	}
};

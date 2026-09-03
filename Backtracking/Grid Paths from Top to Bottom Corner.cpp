// TC: O(P × (n+m)) SC: O(P × (n+m))
class Solution {
	public:
	void pathFinder(int row, int col, vector<vector<int>> &mat, vector<int> currPath,
	vector<vector<int>> &allPaths) {
		
		if (row<0 || col<0 || row >= mat.size() || col >= mat[0].size())
			return;
		
		currPath.emplace_back(mat[row][col]);
		
		if (row == mat.size() - 1 && col == mat[0].size() - 1) {
			allPaths.emplace_back(currPath);
			return;
		}
		
		
		pathFinder(row, col + 1, mat, currPath, allPaths);
		pathFinder(row + 1, col, mat, currPath, allPaths);
		
	}
	vector<vector<int>> allPaths(vector<vector<int>> & mat) {
		// code here
		vector<vector<int>> allPaths;
		vector<int> currPath;
		
		pathFinder(0, 0, mat, currPath, allPaths);
		return allPaths;
	}
};

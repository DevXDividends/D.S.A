// TC:O(N^#) SC:(1)
class Solution {
	public:
	void floydWarshall(vector<vector<int>> &matrix) {
		
		int n = matrix.size();
		const int INF = 100000000;
		
		for (int via = 0; via < n; via++) {
			
			for (int i = 0; i < n; i++) {
				
				for (int j = 0; j < n; j++) {
					
					if (matrix[i][via] != INF &&
					matrix[via][j] != INF) {
						
						matrix[i][j] = min(
						matrix[i][j],
						matrix[i][via] + matrix[via][j]
						);
					}
				}
			}
		}
	}
};

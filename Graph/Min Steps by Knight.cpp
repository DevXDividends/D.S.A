// TC:O(n^2) SC:O(n^2)
class Solution {
	public:
	int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
		
		vector<vector<bool>> vis(n, vector<bool>(n, false));
		queue<pair<pair<int, int>, int>> q;
		
		int k_row = knightPos[0]-1;
		int k_col = knightPos[1]-1;
		
		int t_row = targetPos[0]-1;
		int t_col = targetPos[1]-1;
		
		q.push({{k_row, k_col}, 0});
		vis[k_row][k_col] = true;
		
		int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
		int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};
		
		while (!q.empty()) {
			auto it = q.front();
			q.pop();
			
			int row = it.first.first;
			int col = it.first.second;
			int step = it.second;
			
			if (row == t_row && col == t_col)
				return step;
			
			for (int i = 0; i<8; i++) {
				int newr = row + dr[i];
				int newc = col + dc[i];
				
				if (newr<0 || newr >= n || newc<0 || newc >= n || vis[newr][newc])
					continue;
				
				q.push({{newr, newc}, step + 1});
				vis[newr][newc] = true;
				
			}
		}
		return - 1;
		
	}
};

// TC:O(V + E) SC:O(n) 
class Solution {
	public:
	vector<int> bfs(vector<vector<int>> &adj) {
		// code here
		int n = adj.size();
		vector<int> vis(n, 0);
		vis[0] = 1;
		queue<int> q;
		q.push(0);
		vector<int> bfs;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			bfs.emplace_back(node);
			for (auto it:adj[node]) {
				if (!vis[it]) {
					vis[it] = 1;
					q.push(it);
					
				}
			}
		}
		return bfs;
	}
	
};

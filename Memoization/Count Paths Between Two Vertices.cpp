// TC:O(V + E) SC:O(V + E)
class Solution {
	public:
	int dfs(int node, int &dest, vector<vector<int>> &adj, vector<int> &memo) {
		if (node == dest) {
			return 1;
		}
		if (memo[node] != -1)
			return memo[node];
		
		int paths = 0;
		
		for (auto n:adj[node]) {
			paths += dfs(n, dest, adj, memo);
		}
		memo[node] = paths;
		return memo[node];
	}
	int countPaths(int V, vector<vector<int>> & edges, int src, int dest) {
		// code here
		vector<vector<int>> adj(V);
		for (int i = 0; i<edges.size(); i++) {
			int u = edges[i][0];
			int v = edges[i][1];
			adj[u].emplace_back(v);
		}
		vector<int> memo(V,-1);
		return dfs(src, dest, adj, memo);
		
	}
};

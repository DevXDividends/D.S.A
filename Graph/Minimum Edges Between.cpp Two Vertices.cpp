// TC:O(V + E) SC:O(V + E)
class Solution {
	public:
	int minEdges(int V, vector<vector<int>> & edges, int u, int v) {
		// code here
		vector<vector<int>> adj(V);
		for (auto it:edges) {
			int u = it[0];
			int v = it[1];
			adj[u].emplace_back(v);
			adj[v].emplace_back(u);
		}
		
		vector<bool> vis(V, false);
		queue<pair<int, int>> q;
		q.push({u, 0});
		vis[u] = true;
		while (!q.empty()) {
			auto [node, steps] = q.front();
			q.pop();
			
			if (node == v)return steps;
			for (auto neigh:adj[node]) {
				if (!vis[neigh]) {
					vis[neigh] = true;
					q.push({neigh, steps + 1});
				}
			}
			
		}
		return - 1;
	}
};

// TC:O(V + E) SC:O(V + E)
class Solution {
	public:
	int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
		vector<vector<int>> adj(V);
		
		for (int i = 0; i<edges.size(); i++) {
			int u = edges[i][0];
			int v = edges[i][1];
			adj[u].emplace_back(v);
			adj[v].emplace_back(u);
		}
		
		vector<bool> vis(V, false);
		
		queue<pair<int, int>> q;
		q.push({src, 0});
		vis[src] = true;
		
		while (!q.empty()) {
			auto [node, dist] = q.front();
			q.pop();
			
			if (node == dest)
				return dist;
			
			for (auto neigh:adj[node]) {
				if (!vis[neigh]) {
					q.push({neigh, dist + 1});
					vis[neigh] = true;
				}
			}
		}
		return - 1;
		
	}
};

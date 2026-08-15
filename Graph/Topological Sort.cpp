// TC:O(V + E) SC:O(V + E)
class Solution {
	public:
	
	void dfs(int node, vector<vector<int>> & adj,
	vector<int>& vis, stack<int>& st) {
		
		vis[node] = 1;
		
		for (auto neighbour : adj[node]) {
			if (!vis[neighbour]) {
				dfs(neighbour, adj, vis, st);
			}
		}
		st.push(node);
	}
	
	vector<int> topoSort(int V, vector<vector<int>> & edges) {
		
		vector<vector<int>> adj(V);
		
		for (auto edge : edges) {
			int u = edge[0];
			int v = edge[1];
			
			adj[u].push_back(v);
		}
		
		vector<int> vis(V, 0);
		stack<int> st;
		
		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				dfs(i, adj, vis, st);
			}
		}
		
		vector<int> ans;
		
		while (!st.empty()) {
			ans.push_back(st.top());
			st.pop();
		}
		
		return ans;
	}
};

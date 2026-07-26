// TC:O(V + E) SC;O(n) 
class Solution {
	public:
	void DFS(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &ans) {
		vis[node] = true;
		ans.emplace_back(node);
		for (auto it:adj[node]) {
			if (!vis[it])
				DFS(it, adj, vis, ans);
		}
	}
	vector<int> dfs(vector<vector<int>> & adj) {
		// Code here
		int n = adj.size();
		vector<bool> vis(n, false);
		vector<int> ans;
		DFS(0, adj, vis, ans);
		return ans;
	}
};

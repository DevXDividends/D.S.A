// TC:O(V² + V + E) → O(V²) SC:O(V + E)
class Solution {
public:
    void dfs(int node, vector<bool>& vis, vector<vector<int>>& adj) {
        vis[node] = true;
        for (int n : adj[node]) {
            if (!vis[n])
                dfs(n, vis, adj);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) { // Ignore self-loops
                    adj[i].push_back(j);
                }
            }
        }
        int cnt = 0;
        vector<bool> vis(adj.size(), false);
        for (int i = 0; i < adj.size(); i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, vis, adj);
            }
        }
        return cnt;
    }
};

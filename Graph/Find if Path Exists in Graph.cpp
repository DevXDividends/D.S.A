// TC:O(V + E) SC:O(V + E)
class Solution {
public:
    bool dfs(int node, vector<vector<int>> & adj, vector<bool>& vis,int destination) {
        if (vis[node])
            return;
        if (node == destination) {
            return true;
        }
        vis[node] = true;
        for (auto n : adj[node]) {
            if (!vis[n])
                if(dfs(n, adj, vis,destination))
                return true;
                
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n, false);

     return   dfs(source, adj, vis, destination);
    }
};

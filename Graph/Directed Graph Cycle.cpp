// TC:O(V + E) SC:O(V)
class Solution {
public:

    bool dfs(int node, vector<vector<int>> &graph,
             vector<bool> &vis, vector<bool> &path) {

        vis[node] = true;
        path[node] = true;

        for (auto n : graph[node]) {

            if (!vis[n]) {

                if (dfs(n, graph, vis, path))
                    return true;
            }
            else if (path[n]) {
                return true;
            }
        }

        path[node] = false;

        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &graph) {

        vector<vector<int>> adj(V);

        // Directed graph → ONLY u → v
        for (int i = 0; i < graph.size(); i++) {

            int u = graph[i][0];
            int v = graph[i][1];

            adj[u].push_back(v);
        }

        vector<bool> vis(V, false);
        vector<bool> path(V, false);

        for (int i = 0; i < V; i++) {

            if (!vis[i]) {

                if (dfs(i, adj, vis, path))
                    return true;
            }
        }

        return false;
    }
};

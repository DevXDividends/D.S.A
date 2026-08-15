// TC:O(V + E) SC:O(V)
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<bool>& vis,
             vector<bool>& path) {

        vis[node] = true;
        path[node] = true;

        for (auto n : graph[node]) {

            if (!vis[n]) {

                if (dfs(n, graph, vis, path))
                    return true;
            } else if (path[n]) {
                return true;
            }
        }

        path[node] = false;

        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool> vis(V, false);
        vector<bool> path(V, false);
        vector<int> safeNodes;

        for (int i = 0; i < V; i++) {

            if (!vis[i]) {

                dfs(i, graph, vis, path);
            }
        }
        for (int i = 0; i < V; i++)
            if (!path[i])
                safeNodes.emplace_back(i);
        return safeNodes;
    }
};

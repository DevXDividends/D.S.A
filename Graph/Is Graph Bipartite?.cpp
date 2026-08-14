// TC:O(V + E) SC:O(V)
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, int grp,
             int parent) {
        vis[node] = grp;
        for (auto n : graph[node]) {
            if (vis[n] == grp)
                return false;
            if (vis[n] == 0) {
                int newGrp = grp == 1 ? 2 : 1;
                if (!dfs(n, graph, vis, newGrp, node))
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (!dfs(i, graph, vis, 1, -1))
                    return false;
            }
        }
        return true;
    }
};

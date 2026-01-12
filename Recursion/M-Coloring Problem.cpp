// TC:O(m^V) SC:O(V + E)
class Solution {
public:
    bool isPossible(int node, int col,vector<vector<int>> &adj,vector<int> &color) {
        
        for (int neighbor : adj[node]) {
            if (color[neighbor] == col)
                return false;
        }
        return true;
    }

    bool solve(int node, int m,vector<vector<int>> &adj,vector<int> &color) {
        
        if (node == adj.size())
            return true;

        for (int c = 1; c <= m; c++) {
            if (isPossible(node, c, adj, color)) {
                color[node] = c;
                if (solve(node + 1, m, adj, color))
                    return true;
                color[node] = 0; // backtrack
            }
        }
        return false;
    }

    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        vector<vector<int>> adj(v);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> color(v, 0);
        return solve(0, m, adj, color);
    }
};

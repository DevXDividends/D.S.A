// TC:O(E + V) SC:O(V)
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 2);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        for (int i = 0; i < adj.size(); i++) {
            if (adj[i].size() == n)
                return i;
        }
        return -1;
    }
};
 // TC:O(1) SC:O(1) 

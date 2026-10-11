// TC :O(V alpha(V)) SC:O(V)
class Disjoint {
    vector<int> parent, size;

public:
    Disjoint(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]);
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        Disjoint ds(n);
        int extraU, extraV;
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];

            if (ds.findUParent(u) == ds.findUParent(v)) {
                extraU = u;
                extraV = v;
            } else
                ds.unionBySize(u, v);
        }
        return {extraU, extraV};
    }
};

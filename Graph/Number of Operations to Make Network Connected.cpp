// TC:O(N + M alpha(N)) SC:O(N)
class Disjoint {
public:
    vector<int> parent, size;
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
    int makeConnected(int n, vector<vector<int>>& connections) {

        Disjoint ds(n);
        int cntExtraEdges = 0;
        for (auto it : connections) {
            int u = it[0];
            int v = it[1];

            if (ds.findUParent(u) == ds.findUParent(v))
                cntExtraEdges++;
            else
                ds.unionBySize(u, v);
        }
        int cntC = 0;
        for (int i = 0; i < n; i++)
            if (ds.parent[i] == i)
                cntC++;

        return cntExtraEdges >= cntC - 1 ? cntC - 1 : -1;
    }
};

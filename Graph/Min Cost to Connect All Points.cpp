// TC:O(N^2 log N) SC:O(N^2)

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
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> edges;
        // prepare the edges graph first
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int wt = abs(points[i][0] - points[j][0]) +
                         abs(points[i][1] - points[j][1]);
                edges.push_back({wt, i, j});
            }
        }
        sort(edges.begin(), edges.end());
        int minCost = 0;
        Disjoint ds(n);
        for (auto it : edges) {
            int wt = it[0];
            int u = it[1];
            int v = it[2];

            if (ds.findUParent(u) != ds.findUParent(v)){
                minCost += wt;
                ds.unionBySize(u,v);
            }
        }
        return minCost;
    }
};

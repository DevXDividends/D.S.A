// TC:O(N^2) SC:O(rows *  cols)
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
    bool isValid(int newr, int newc, int n, int m) {
        return newr >= 0 && newr < n && newc >= 0 && newc < m;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        Disjoint ds(rows * cols);

        // Step 1: Connect adjacent land cells.
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0)
                    continue;

                for (int ind = 0; ind < 4; ind++) {
                    int newr = i + dr[ind];
                    int newc = j + dc[ind];

                    if (isValid(newr, newc, rows, cols) &&
                        grid[newr][newc] == 1) {
                        int nodeNo = i * cols + j;
                        int adjNodeNo = newr * cols + newc;

                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }

        // Step 2: Try converting each zero into land.
        int mx = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1)
                    continue;

                set<int> components;

                for (int ind = 0; ind < 4; ind++) {
                    int newr = i + dr[ind];
                    int newc = j + dc[ind];

                    if (isValid(newr, newc, rows, cols) &&
                        grid[newr][newc] == 1) {
                        components.insert(ds.findUParent(newr * cols + newc));
                    }
                }

                int sizeTotal = 1;

                for (auto it : components)
                    sizeTotal += ds.size[it];

                mx = max(mx, sizeTotal);
            }
        }

        // Step 3: Handle the case where all cells are already land.
        for (int i = 0; i < rows * cols; i++) {
            mx = max(mx, ds.size[ds.findUParent(i)]);
        }

        return mx;
    }
};

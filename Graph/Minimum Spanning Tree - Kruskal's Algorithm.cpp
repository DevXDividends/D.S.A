// TC:O( E log E) SC:O(V + log V) 
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
		
		if (size[ulp_u]<size[ulp_v]) {
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
	int kruskalsMST(int V, vector<vector<int>> &edges) {
		sort(edges.begin(), edges.end(),
		[](vector<int> &a, vector<int> &b) {
			return a[2]<b[2];
    		}
		);
		
		int mstWt = 0;
		Disjoint ds(V);
		
		for (auto it:edges) {
			int u = it[0];
			int v = it[1];
			int wt = it[2];
			
			if (ds.findUParent(u) != ds.findUParent(v)) {
				mstWt += wt;
				ds.unionBySize(u, v);
			}
		}
		return mstWt;
		
	}
};

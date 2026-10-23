// TC:(O(V + E xalpha(V)) SC:O(V)
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
	bool detectCycle(int V, vector<int> adj[]) {
		// Code here
		Disjoint ds(V);
		for (int i = 0; i<V; i++) {
			for (int j = 0; j<adj[i].size(); j++) {
				int u = i;
				int v = adj[i][j];
				
				// Process each undirected edge only once
				if (u < v) {
					int up = ds.findUParent(u);
					int vp = ds.findUParent(v);
					
					if (up == vp)
						return true;
					
					ds.unionBySize(u, v);
				}
			}
		}
		return false;
		
	}
};

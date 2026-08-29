// TC:O(E log V) SC:O(V) 
class Solution {
	public:
	vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
		
		vector<vector<pair<int, int>> > adj(V);
		
		for (auto &e : edges) {
			int u = e[0];
			int v = e[1];
			int wt = e[2];
			
			adj[u].push_back({v, wt});
			adj[v].push_back({u, wt});
		}
		
		priority_queue<
		pair<int, int>,
		vector<pair<int, int>>,
		greater<pair<int, int>>
		> pq;
		
		vector<int> dist(V, 1e9);
		
		dist[src] = 0;
		pq.push({0, src});
		
		while (!pq.empty()) {
			
			int currDist = pq.top().first;
			int node = pq.top().second;
			pq.pop();
			
			// Ignore outdated entry
			if (currDist > dist[node])
				continue;
			
			for (auto it : adj[node]) {
				
				int adjNode = it.first;
				int edgeWeight = it.second;
				
				if (currDist + edgeWeight < dist[adjNode]) {
					
					dist[adjNode] = currDist + edgeWeight;
					
					pq.push({dist[adjNode], adjNode});
				}
			}
		}
		
		return dist;
	}
};

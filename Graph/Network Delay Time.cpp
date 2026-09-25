TC :O(E log V) SC:O(V + E)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // Nodes are 1...n, so use n + 1
        vector<vector<pair<int, int>>> adj(n + 1);

        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int time = times[i][2];

            adj[u].push_back({v, time});
        }

        vector<int> dist(n + 1, 1e9);

        // {time, node}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {

            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node]) {

                int adjNode = it.first;
                int curTime = it.second;

                if (time + curTime < dist[adjNode]) {

                    dist[adjNode] = time + curTime;

                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int maxTime = 0;

        for (int i = 1; i <= n; i++) {

            if (dist[i] == 1e9)
                return -1;

            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};

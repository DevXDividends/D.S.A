// TC: O(E log V)  SC: O(V + E)
class Solution {
public:
    int spanningTree(int V, vector<vector<int>> &edges) {

        vector<vector<pair<int, int>>> adj(V);

        for (auto e : edges) {
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

        vector<bool> vis(V, false);

        pq.push({0, 0});

        int sum = 0;

        while (!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            int wt = it.first;
            int node = it.second;

            if (vis[node])
                continue;

            vis[node] = true;
            sum += wt;

            for (auto n : adj[node]) {

                int adjNode = n.first;
                int edw = n.second;

                if (!vis[adjNode])
                    pq.push({edw, adjNode});
            }
        }

        return sum;
    }
};

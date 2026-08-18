// TC:O(V + E) SC:O(V)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<int> adj[numCourses];

        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].emplace_back(u);
        }

        vector<int> indegree(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            for (auto n : adj[i]) {
                indegree[n]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.emplace_back(node);

            // Process neighbors of node
            for (auto n : adj[node]) {
                indegree[n]--;

                if (indegree[n] == 0) {
                    q.push(n);
                }
            }
        }
        return topo.size()== numCourses?topo:vector<int>{};

    }
};

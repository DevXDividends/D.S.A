// TC:O(V + E) SC:O(V) 
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (vis[node])
                continue;
            vis[node] = true;
            for (auto neigh : rooms[node]) {
                if (!vis[neigh])
                    q.push(neigh);
            }
        }
        for (int i=0;i<n;i++)
            if (vis[i] == false)
                return false;

        return true;
    }
};

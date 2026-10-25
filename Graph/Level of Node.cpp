// TC:O(V + E) SC:O(V + E)
class Solution {
  public:
    int nodeLevel(int V, vector<vector<int>>& edges, int x) {
        vector<vector<int>> adj(V);
        for(auto it :edges)
        adj[it[0]].emplace_back(it[1]);
        
        queue<pair<int,int>> q;
        vector<bool> vis(V,false);
        
        q.push({0,0});
        vis[0] =true;
        while(!q.empty()){
            auto [node,steps] = q.front();
            q.pop();
            
            if(node == x)
            return steps;
            
            for(auto adjNode:adj[node]){
                if(!vis[adjNode])
                {
                    vis[adjNode] = true;
                    q.push({adjNode,steps+1});
                }
            }
        }
        return -1;
    }
};

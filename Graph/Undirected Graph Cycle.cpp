/* 1. using DFS
TC:O(V + E) SC:O(V + E)
*/
class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> adj[V];
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){
        if(vis[i])continue;
        
        queue<pair<int,int>> q; // {node,parent}
        q.push({i,-1});
        vis[i]= true;
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto n:adj[node]){
                if(!vis[n]){
                    q.push({n,node});
                    vis[n] =true;
                }else if (vis[n] && parent!=n)
                return true;
            }
        }
        }
        return false;
    }
};

/*
using DFS
TC:O(V + E) SC:O(V + E)
*/
class Solution {
  public:
  bool dfs(int node,int parent,vector<vector<int>> &adj,vector<bool> &vis){
      vis[node] = true;
      for(auto n:adj[node]){
          if(!vis[n]){
              if(dfs(n,node,adj,vis))
              return true;
          }else if (parent !=n)
          return true;
      }
      return false;
  }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i])
            if(dfs(i,-1,adj,vis))
            return true;
        }
        return false;
    }
};

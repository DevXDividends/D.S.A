// TC:O(V + E) SC:O(1) 
class Solution {
  public:
    bool checkEdge(vector<vector<int>>& adj, int u, int v) {
        // code here
        int n = adj.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<adj[i].size();j++)
            if(i == u && adj[i][j] == v)return true;
        }
        return false;
    }
};

// TC:O(V + E) SC:O(V + E)
class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // code here
       int row = grid.size();
       int col = grid[0].size();
       vector<vector<bool>> vis(row,vector<bool>(col,false));
       queue<pair<pair<int,int>,int>> q;
       vector<vector<int>> ans(row,vector<int>(col,-1));
       for(int i=0;i<row;i++){
           for(int j=0;j<col;j++){
               if(grid[i][j]){
                   vis[i][j] = true;
                   q.push({{i,j},0});
               }
           }
       }
       int drow[] = {-1,0,1,0};
       int dcol[] = {0,1,0,-1};
       while(!q.empty()){
           int r = q.front().first.first;
           int c = q.front().first.second;
           int steps=  q.front().second;
           q.pop();
           ans[r][c] = steps;
           for(int i = 0;i<4;i++){
                   int nrow = r + drow[i];
                   int ncol = c + dcol[i];
                   if(nrow>=0 && ncol>=0 && nrow<row && ncol<col && !vis[nrow][ncol]){
                       vis[nrow][ncol] = true;
                       q.push({{nrow,ncol},steps+1});
                   }
               
           }
           
       }
       return ans;
       
       
       
    }
};

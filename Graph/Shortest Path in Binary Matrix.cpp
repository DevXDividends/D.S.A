// TC:O(n^2) SC:O(n^2) 
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        if (rows == 1 && cols == 1 && grid[0][0] == 0)
            return 1;
        else if (rows == 1 && cols == 1 && grid[0][0] == 1)
            return -1;
        if (grid[0][0] == 1 || grid[rows - 1][cols - 1] == 1)
            return -1;
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(rows, vector<int>(cols, 1e9));
        dist[0][0] = 1;
        q.push({1, {0, 0}});
        int drow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dcol[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        while (!q.empty()) {
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            for (int i = 0; i < 8; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols &&
                    !grid[nrow][ncol] && dist[nrow][ncol] > dis + 1) {
                    dist[nrow][ncol] = dis + 1;
                    if (nrow == rows - 1 && ncol == cols - 1)
                        return dis + 1;
                    q.push({dis + 1, {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};

// TC:O(n x m) SC:O(n x m)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));
        int timeTaken = 0;
        // {{row,col},time}
        queue<pair<pair<int, int>, int>> q;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        int cntFresh = 0;
        // find all the initial rotten oranges and put into queue & vis
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                if (grid[i][j] == 1)
                    cntFresh++;
            }
        }
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            timeTaken = max(timeTaken, t);
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && ncol >= 0 && nrow < row && ncol < col &&
                    !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                    cntFresh--;
                }
            }
        }
        return cntFresh != 0 ? -1 : timeTaken;
    }
};

// TC = O(R × C × log(R × C)) SC = O(R × C)
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        vector<vector<int>> dist(rows, vector<int>(cols, 1e9));
        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if (row == rows - 1 && col == cols - 1)
                return diff;
            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i];
                int nc = col + dc[i];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    int newEff =
                        max(abs(heights[row][col] - heights[nr][nc]), diff);
                    if (newEff < dist[nr][nc]) {
                        dist[nr][nc] = newEff;
                        pq.push({newEff, {nr, nc}});
                    }
                }
            }
        }
        return 0;
    }
};

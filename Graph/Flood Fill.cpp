// TC:O(m * n) SC:O(m * n) 
class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& image, int& originalColor,
             int& color) {
        if (row < 0 || col < 0 || row >= image.size() || col >= image[0].size())
            return;
        if (image[row][col] != originalColor)
            return;
        if (image[row][col] == color)
            return;
        image[row][col] = color;

        int wr[] = {-1, 0, 1, 0};
        int wc[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nr = row + wr[i];
            int nc = col + wc[i];
            dfs(nr, nc, image, originalColor, color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int row = image.size();
        int col = image[0].size();
        int originalColor = image[sr][sc];

        dfs(sr, sc, image, originalColor, color);
        return image;
    }
};

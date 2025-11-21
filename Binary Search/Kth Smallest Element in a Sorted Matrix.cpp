// TC:O(n · log(maxValue)) SC:O(1)
class Solution {
public:
    int countSmallerNumbers(vector<vector<int>>& matrix, int mid) {
        int n = matrix.size();
        int row = 0;
        int col = n - 1;
        int cnt = 0;
        while (row < n && col >= 0) {
            if (matrix[row][col] <= mid) {
                cnt += (col + 1);
                row++; // go down
            } else
                col--;
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        if (rows * cols < 2)
            return matrix[rows - 1][cols - 1];
        int low = matrix[0][0];
        int high = matrix[rows - 1][cols - 1];
        while (low < high) {
            int mid = low + (high - low) / 2;

            if (countSmallerNumbers(matrix, mid) < k)
                low = mid + 1; // go left and find greater no
            else {
                high = mid; // go right and find smaller no
            }
        }
        return low;
    }
};

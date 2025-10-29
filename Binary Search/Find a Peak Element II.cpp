// brute force TC:O(rows * cols) SC:O(1)
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int peak = 0;
        int ind1=-1,ind2=-1;
        int rows = mat.size();
        int cols = mat[0].size();

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(mat[i][j] >peak) {
                    peak = mat[i][j];
                    ind1=i;
                    ind2=j;
                }
            }
        }
        return {ind1,ind2};

    }
};
// TC:O(rows *log cols) SC:O(1)
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // in this soluiton we apply bs on colums
        int rows = mat.size();
        int cols = mat[0].size();
        int low = 0, high = cols - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // calculate the max element of that row
            int row = 0;
            for (int i = 0; i < rows; i++)
                if (mat[i][mid] > mat[row][mid])
                    row = i;

            // we have the max element of the col
            // now we compare it with left and right values to check is there is
            // a greater number on either side
            int left = (mid - 1 >= 0) ? mat[row][mid - 1] : -1;
            int right = (mid + 1 < cols) ? mat[row][mid + 1] : -1;
            if(mat[row][mid]>left && mat[row][mid]>right) return {row,mid};
            if(mat[row][mid] <right) low=mid+1;
            else high=mid-1;
        }
        return {-1,-1};
    }
};

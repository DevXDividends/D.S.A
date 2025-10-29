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

// brute TC:O(rows * cols) SC:O(1)
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        int maxCnt = 0;
        int ind=0;
        for (int i = 0; i < rows; i++) {
            int cnt = 0;
            for (int j = 0; j < cols; j++) {
                if (mat[i][j]) {
                    cnt++;
                    if(cnt>maxCnt){
                        maxCnt = cnt;
                        ind =  i;
                    }
                    
                }
            }
        }
        return {ind,maxCnt};
    }
};

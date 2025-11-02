// TC:O(n × m × log(n × m)) SC:O(n × m)
class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        vector<int> ans;
        int rows = mat.size();
        int cols = mat[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                ans.emplace_back(mat[i][j]);
            }
        }
        sort(ans.begin(),ans.end());
        return (ans[ans.size()/2]);
    }
};
class Solution {
public:
    int countSmallerEqual(vector<vector<int>> &mat, int x) {
        int cnt = 0;
        for (int i = 0; i < mat.size(); i++) {
            cnt += upper_bound(mat[i].begin(), mat[i].end(), x) - mat[i].begin();
        }
        return cnt;
    }
// TC: O(rows × log(maxVal - minVal) × log(cols)) SC: O(1)
    int median(vector<vector<int>> &mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        int low = INT_MAX, high = INT_MIN;
        for (int i = 0; i < rows; i++) {
            low = min(low, mat[i][0]);              
            high = max(high, mat[i][cols - 1]);    
        }
        int required = (rows * cols) / 2; 
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = countSmallerEqual(mat, mid);
            if (count <= required)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};

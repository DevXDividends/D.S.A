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

// optimal (if each row is sorted in matrix) TC:O(rows * log n) SC:O(1)
class Solution {
  public:
  int bs(vector<int> &a){
      int low = 0,high=a.size()-1;
      while(low<=high){
          int mid= low+(high-low)/2;
          if(a[mid]) high=mid-1;
          else low=mid+1;
      }
      return low;
  }
  
    int rowWithMax1s(vector<vector<int>> &arr) {
        int rows = arr.size();
        int cols =arr[0].size();
        int maxCnt = 0;
        int idx = 0;
        for(int i=0;i<rows;i++){
            int cnt = cols  - bs(arr[i]);
            if(cnt>maxCnt){
                maxCnt=cnt;
                idx = i;
            }
        }
        return idx;
    }
};

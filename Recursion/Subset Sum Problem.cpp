// TC:O(n * sum) SC:O(sum)   (bottom-up DP, 1D)
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        if (sum < 0) return true;
        vector<char> dp(sum + 1, 0);
        dp[0] = 1;
        for (int x : arr) {
            for (int s = sum; s >= x; s--) {
                if (dp[s - x]) dp[s] = 1;
            }
        }
        return dp[sum];
    }
};

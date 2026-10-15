// TC:O(n) SC:O(1)
class Solution {
  public:
    long long maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        long long windowSum = 0;
        for (int i = 0; i < k; i++)
            windowSum += arr[i];
        long long maxSum = windowSum;
        for (int r = k; r < n; r++) {
            windowSum += arr[r];
            windowSum -= arr[r - k];
            maxSum = max(maxSum, windowSum);
        }
        return maxSum;
    }
};

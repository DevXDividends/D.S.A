// TC:O(N^2) SC:O(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        for (int st = 0; st < n; st++) {
            int zeros = 0;
            for (int end = st; end < n; end++) {
                if (nums[end] == 0)
                    zeros++;
                if (zeros <= k)
                    maxLen = max(maxLen, (end - st) + 1);
                else
                    break;
            }
        }
        return maxLen;
    }
};
// TC:O(n) SC:O(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int maxLen = 0;
        int zeros = 0;
        while (r < n) {
            if (nums[r] == 0)
                zeros++;
            if (zeros > k) {
                if (nums[l] == 0)
                    zeros--;
                l++;
            }
            if (zeros <= k)
                maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};

//  brute TC:O(n^2) SC:O(1)
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            int commulativeBits = 0;
            for (int j = i; j < n; j++) {
                if ((commulativeBits & nums[j]) == 0) {
                    maxLen = max(maxLen, j - i + 1);
                    commulativeBits |= nums[j];
                } else
                    break;
            }
        }
        return maxLen;
    }
};
// TC:O(n) SC:O(1)
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();

        int l = 0;
        int mask = 0;
        int ans = 1;

        for (int r = 0; r < n; r++) {

            // Keep shrinking until the current number has
            // no overlapping bits with the window.
            while ((mask & nums[r]) != 0) {
                mask ^= nums[l];
                l++;
            }

            // Add current number to the window
            mask |= nums[r];

            // Update answer
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

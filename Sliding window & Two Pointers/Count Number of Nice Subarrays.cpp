// brute TC:O(n^2) SC:O(1)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int cntOdd = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] % 2 != 0)
                    cntOdd++;
                if (cntOdd == k)
                    cnt++;
            }
        }
        return cnt;
    }
};
// optimal TC:o(N) SC:O(1)
class Solution {
public:
    int AtMost(vector<int>& nums, int k) {
        if (k < 0)
            return 0;
        int n = nums.size();
        int ans = 0;
        int l = 0, r = 0;
        int cntOdd = 0;
        while (r < n) {
            if (nums[r] % 2 != 0)
                cntOdd++;
            while (cntOdd > k) {
                if (nums[l] % 2 != 0)
                    cntOdd--;
                l++;
            }
            if (cntOdd <= k)
                ans += (r - l) + 1;
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return AtMost(nums,k) - AtMost(nums,k - 1);
    }
};

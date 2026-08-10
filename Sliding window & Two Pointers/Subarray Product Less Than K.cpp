// TC:O(n^2) SC:O(1) 
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            long long prod = 1;
            for (int j = i; j < n; j++) {
                if (prod * nums[j] > LLONG_MAX)
                    break;
                prod *= nums[j];
                if (prod < k)
                    cnt++;
                else
                    break;
            }
        }
        return cnt;
    }
};
// TC:O(n) SC:O(1)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        int l = 0, r = 0;
        long long prod = 1;
        while (r < n) {
            prod *= nums[r];
            while (prod >= k && l <= r) {
                prod /= nums[l++];
            }
            if (prod < k)
                cnt += r - l + 1;
            r++;
        }
        return cnt;
    }
};

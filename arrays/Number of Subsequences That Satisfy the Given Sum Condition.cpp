// TC:O(n log n ) + O(n) SC:O(n)
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int mod = 1e9 + 7; // this to just  to prevent interger overflow
        int n = nums.size();
        vector<int> power(n, 1);
        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2) % mod;
        }
        int left = 0, right = n - 1, cnt = 0;
        while (left <= right) {
            int sum = nums[left] + nums[right];
            if (sum > target)
                right--;
            else
                cnt = (cnt + power[right - left++]) % mod;
        }
        return cnt;
    }
};

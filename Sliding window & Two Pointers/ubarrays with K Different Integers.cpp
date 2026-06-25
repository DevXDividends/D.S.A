// brute TC:O(n^2) SC:O(k) 
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> stt;
            for (int j = i; j < n; j++) {
                stt.insert(nums[j]);
                if (stt.size() > k)
                    break;
                if (stt.size() == k)
                    cnt++;
            }
        }
        return cnt;
    }
};
// optimal TC:O(n) SC:O(1)
class Solution {
public:
    int AtMost(vector<int>& nums, int k, int n) {
        if (k <= 0)
            return 0;
        int cnt = 0;
        int l = 0, r = 0;
        unordered_map<int, int> mpp;
        while (r < n) {
            mpp[nums[r]]++;
            while (mpp.size() > k) {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0)
                    mpp.erase(nums[l]);
                l++;
            }
            if (mpp.size() <= k)
                cnt += r - l + 1;
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        return AtMost(nums, k, n) - AtMost(nums, k - 1, n);
    }
};

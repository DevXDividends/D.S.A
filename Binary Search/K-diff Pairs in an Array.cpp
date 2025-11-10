// TC:O(n^2) SC:O(1)
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int maxCnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size(); j++) {

                if (abs(nums[i] - nums[j]) == k) {
                    maxCnt++;
                    break;
                } else if (abs(nums[i] - nums[j]) > k) {
                    break;
                }
            }
        }
        return maxCnt;
    }
};
